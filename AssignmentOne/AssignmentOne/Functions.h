#pragma once
class Functions
{

public:
	Functions();
	~Functions();
	static LinkedListNode* ReadFile(LinkedListNode* head); 
	static void Menu(); 
	static LinkedListNode* Insert(LinkedListNode* head, std::string name, int id); 
	static void DisplayList(LinkedListNode* head); 
	static LinkedListNode* Delete(LinkedListNode* head, int id); 
	static LinkedListNode* Delete(LinkedListNode* head, std::string name); 

};

