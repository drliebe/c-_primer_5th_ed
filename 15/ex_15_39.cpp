#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <iterator>

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() -1;
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std::set<TextQuery::line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, 
		    std::shared_ptr<std::set<TextQuery::line_no>> p,
		    std::shared_ptr<std::vector<std::string>> f) :
		    sought(s), lines(p), file(f)  {  }
	std::set<TextQuery::line_no>::iterator begin() {return lines->begin();}
	std::set<TextQuery::line_no>::iterator end()   {return lines->end();}
	std::shared_ptr<std::vector<std::string>> get_file() {return file;}
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};


QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " times." << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num+1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}

void runQueries(std::ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		std::cout << "enter word to look for, or q to quit: ";
		std::string s;
		if (!(std::cin>>s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}



class Query_base
{
public:
	friend class Query;
	Query_base() {std::cout << "Query_base::Query_base()" << std::endl;}
protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const { std::cout << "Query_base::rep)" << std::endl; return " ";};
};


class Query
{
public:
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
	
	Query(const std::string &);
	QueryResult eval(const TextQuery &t) const {return q->eval(t);}
	std::string rep() const { std::cout << "Query::rep()" << std::endl; return q->rep(); }
	
protected:

private:
	Query(std::shared_ptr<Query_base> query) : q(query) { std::cout << "Query::Query(std::shared_ptr<Query_base> query)" << std::endl; }
	std::shared_ptr<Query_base> q;
};

std::ostream &operator<<(std::ostream &os, const Query &query)
{
	return os << query.rep();
}


class WordQuery : public Query_base
{
private:
	friend class Query;
	WordQuery(const std::string &s) : query_word(s) { std::cout << "WordQuery::WordQuery(const std::string &s)" << std::endl; }
	QueryResult eval(const TextQuery &t) const {return t.query(query_word);}
	std::string rep() const {std::cout << "WordQuery::rep()"<< std::endl; return query_word;}
	std::string query_word;
};


inline Query::Query(const std::string &s) : q(new WordQuery(s)) { std::cout << "Query::Query(const std::string &s)" << std::endl; }

	
class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) { std::cout << "NotQuery::NotQuery(const Query &q)" << std::endl; }
	std::string rep() const {std::cout << "NotQuery::rep()" << std::endl; return "~(" + query.rep() + ")";}
	QueryResult eval(const TextQuery &text) const;
	Query query;
};

QueryResult NotQuery::eval(const TextQuery &text) const
{
	auto result = query.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	auto beg = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size();
	for (size_t n=0; n != sz; ++n)
	{
		if (beg == end || *beg !=n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;
	} 
	return QueryResult(rep(), ret_lines, result.get_file());
}

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
};


class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) : lhs(l), rhs(r), opSym(s) 
		{ std::cout << "BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s)" << std::endl; }
	std::string rep() const {std::cout << "BinaryQuery::rep()" << std::endl;
					 return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}
	Query lhs;
	Query rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery
{
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") 
		{ std::cout << "AndQuery::AndQuery(const Query &left, const Query &right)" << std::endl; }
	QueryResult eval(const TextQuery &text) const;
};

QueryResult AndQuery::eval(const TextQuery &text) const
{
	auto left = lhs.eval(text);
	auto right = rhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>();
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
		inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
	friend Query operator|(const Query &lhs, const Query &rhs);
	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|") 
		{ std::cout << "OrQuery::OrQuery(const Query &left, const Query &right)" << std::endl; }
	QueryResult eval(const TextQuery& t) const;
};

QueryResult OrQuery::eval(const TextQuery &text) const
{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
	ret_lines->insert(right.begin(), right.end());
	
	return QueryResult(rep(), ret_lines, left.get_file());
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}



int main(int argv, char** argc)
{
	std::ifstream ifs("test.txt");
	TextQuery txt(ifs);

	Query q = Query("fiery") & Query("bird") | Query("wind");
	std::cout << q << std::endl;
	print(std::cout, q.eval(txt));


	ifs.close();
	return 0;

}











