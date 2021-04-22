#include <iostream>
#include <set>
#include <string>

class Message;


class Folder
{
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder &orig);
	Folder &operator=(const Folder &rhs);
	~Folder();
	void addMsg(Message *msg);
	void remMsg(Message *msg);
	void print();
private:
	std::set<Message*> messages;
	void add_to_Messages(const Folder &f);
	void remove_from_Messages();
};

class Message 
{
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	explicit Message(const std::string &str = ""):
		contents(str) { }
	Message(const Message &cp);
	Message& operator=(const Message &rhs);
	~Message();
	void save(Folder &f);
	void remove(Folder &f);
	void addFolder(Folder *pf);
	void remFolder(Folder *pf);
	std::string &string() {return contents;}
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message &msg);
	void remove_from_Folders();
};

void Message::save(Folder &f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f: m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f: folders)
		f->remMsg(this);
}

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}


Message::~Message()
{
	remove_from_Folders();
}

Message &Message::operator=(const Message &rhs)
{
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void Message::addFolder(Folder *pf)
{
	folders.insert(pf);
}

void Message::remFolder(Folder *pf)
{
	folders.erase(pf);
}

void swap(Message &lhs, Message &rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f: rhs.folders)
		f->addMsg(&rhs);
}





Folder::Folder(const Folder &orig) : messages(orig.messages)
{
	add_to_Messages(orig);
}

Folder &Folder::operator=(const Folder &rhs)
{
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::addMsg(Message *msg)
{
	messages.insert(msg);
}

void Folder::remMsg(Message *msg)
{
	messages.erase(msg);
}

void Folder::print()
{
	for(auto m: messages)
		std::cout << m->string() << std::endl;
}

void Folder::add_to_Messages(const Folder &f)
{
	for(auto m : f.messages)
		m->addFolder(this);
}

void Folder::remove_from_Messages()
{
	for(auto m : messages)
		m->remFolder(this);
}

int main()
{
	Folder f1;
	Folder f2;
	Message m1("Message 1");
	Message m2("Message 2");
	Message m3("Message 3");
	Message m4("Message 4");

	m1.save(f1);
	m2.save(f1);
	m3.save(f2);
	m4.save(f2);

	f1.print();
	f2.print();


	f1 = f2;
	std::cout << "After f1 = f2 " << std::endl;
	f1.print();
	f2.print();
	


	return 0;
}
