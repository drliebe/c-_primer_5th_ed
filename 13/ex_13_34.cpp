#include <iostream>

class Folder;

class Message 
{
	friend class Folder;
public:
	explicit Message(const std::string &str = ""):
		contents(str) { }
	Message(const Message &cp);
	Message& operator=(const Message &rhs);
	~Message();
	void save(Folder &f);
	void remove(Folder &f);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message &msg);
	void remove_from_Folders();
};

void Message::save(Folder &f)
{
	folders.insert(&f)
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

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f: folders)
		f->remMsg(this);
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

int main()
{

	return 0;
}
