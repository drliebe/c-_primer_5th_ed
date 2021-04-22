#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <tuple>


typedef std::tuple< std::string, 
		  std::shared_ptr<std::set<std::vector<std::string>::size_type>>, 
		  std::shared_ptr<std::vector<std::string>> > QueryResultTuple;


class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResultTuple query(const std::string&) const;
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
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};


QueryResultTuple TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<TextQuery::line_no>> nodata(new std::set<TextQuery::line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResultTuple(sought, nodata, file);
	else
		return QueryResultTuple(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResultTuple &qr)
{
	os << std::get<0>(qr) << " occurs " << std::get<1>(qr)->size() << " times." << std::endl;
	for (auto num : *std::get<1>(qr))
		os << "\t(line " << num+1 << ") " << *(std::get<2>(qr)->begin() + num) << std::endl;
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



int main(int argv, char** argc)
{
	std::ifstream ifs(argc[1]);
	
	runQueries(ifs);

	return 0;

}











