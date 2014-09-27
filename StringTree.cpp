#include <iostream>
#include <string.h>
#include <ctype.h>
int flag = 0;
using namespace std;

class StringNode;

class TreeGate
{
protected:
	StringNode *m_Child[26];
	
public:
	TreeGate()
	{
		memset(m_Child,NULL,sizeof(m_Child));
	}

	virtual bool AddString(char str[]);
	virtual bool DeleteString(char str[]);
	virtual bool FindString(char str[]);
	virtual void PrintString();
};


class StringNode : public TreeGate
{
protected:
	char m_String[20];
	bool isEndOfString;

public:
	StringNode()
	{
		memset(m_String,NULL,20);
		isEndOfString = false;
	}

	bool AddString(char str[]);
	bool DeleteString(char str[]);
	bool FindString(char str[]);
	void PrintString();
};


bool TreeGate :: AddString(char str[])
{
	int i=0;
	while(str[i] != NULL)
	{
		if(!isalpha(str[i]))
		{
			return false;
		}
		i++;
	}

	int index;
	if(str[0]>=97 && str[0]<=122)
	{
		index = str[0] - 'a';
	}
	else if(str[0]>=65 && str[0]<=90)
	{
		index = str[0] - 'A';
	}
	
	if(m_Child[index] == NULL)
	{
		m_Child[index] = new StringNode();
		printf("\n%d\t",index);
	}
	
	return (m_Child[index])->AddString(str);
}

bool TreeGate :: DeleteString(char str[])
{
	int index;
	if(str[0]>=97 && str[0]<=122)
	{
		index = str[0] - 'a';
	}
	else if(str[0]>=65 && str[0]<=90)
	{
		index = str[0] - 'A';
	}
	
	if(m_Child[index] == NULL)
	{
		return false;
	}

	bool i = (m_Child[index])->DeleteString(str);

	if(i == true && flag == 1)
	{
		flag = 0;
		delete(m_Child[index]);
		m_Child[index] = NULL;
	}
}

bool TreeGate :: FindString(char str[])
{
	int index;
	if(str[0]>=97 && str[0]<=122)
	{
		index = str[0] - 'a';
	}
	else if(str[0]>=65 && str[0]<=90)
	{
		index = str[0] - 'A';
	}

	if(m_Child[index] == NULL)
	{
		return false;
	}
	
	return (m_Child[index])->FindString(str);
}

void TreeGate :: PrintString()
{
	printf("\n<TG>");
	for(int i=0; i<26 ;i++)
	{
		if(m_Child[i] != NULL)
		{
			(m_Child[i])->PrintString();
		}
	}
	printf("\n</TG>");
}


bool StringNode :: AddString(char str[])
{
	int i=0;
	if(m_String[0] == NULL)
	{
		strcpy(m_String,str);
		isEndOfString = true; 
		puts(m_String);
		return true;
	}
	else
	{
		while(str[i] != NULL)
		{
			while(str[i] == m_String[i])
			{
				if(str[i] == NULL || m_String[i] == NULL)
					break;
				else
					i++;
			}
			

			if(str[i] == NULL && m_String[i] == NULL)
			{
				if(isEndOfString == true)
					return false;
				else
				{
					isEndOfString = true;
					return true;
				}
			}

			char temp[10];
			memset(temp,NULL,10);
			int j=0;
			
			
			
	
			if(m_String[i] == NULL)
			{
				while(str[i] != NULL)
				{
					temp[j] = str[i]; 
					j++;
					i++;
				}

				int index;
				if(temp[0]>=97 && temp[0]<=122)
				{
					index = temp[0] - 'a';
				}
				else if(temp[0]>=65 && temp[0]<=90)
				{
					index = temp[0] - 'A';
				}
				
				if(m_Child[index] == NULL)
				{
					m_Child[index] = new StringNode();
					printf("\n%d\t",index);
				}
	
				return (m_Child[index])->AddString(temp);
			}
			
			else if(str[i] == NULL)
			{
				while(m_String[i] != NULL)
				{
					temp[j] = m_String[i];
					m_String[i] = NULL;
					j++;
					i++;
				}

				puts(m_String);
				int index;
				if(temp[0]>=97 && temp[0]<=122)
				{
					index = temp[0] - 'a';
				}
				else if(temp[0]>=65 && temp[0]<=90)
				{
					index = temp[0] - 'A';
				}
				
				
				if(m_Child[index] == NULL)
				{
					m_Child[index] = new StringNode();
					printf("\n%d\t",index);
					return (m_Child[index])->AddString(temp);
				}
				else
				{
					StringNode *s = new StringNode();
					s->AddString(temp);
					for(int l_index = 0 ; l_index<26 ; l_index++)
					{
						s->m_Child[l_index] = m_Child[l_index];
						m_Child[l_index] = NULL;
					}

					m_Child[index] = s;
					isEndOfString = false;
				}
			}

			else
			{
				int k=i;
				while(m_String[i] != NULL)
				{
					temp[j] = m_String[i];
					m_String[i] = NULL;
					//printf("%c",temp[j]);
					j++;
					i++;
				}

				puts(m_String);
				int index;
				if(temp[0]>=97 && temp[0]<=122)
				{
					index = temp[0] - 'a';
				}
				else if(temp[0]>=65 && temp[0]<=90)
				{
					index = temp[0] - 'A';
				}
				
				
				if(m_Child[index] == NULL)
				{
					m_Child[index] = new StringNode();
					printf("\n%d\t",index);
					return (m_Child[index])->AddString(temp);
				}
				else
				{
					StringNode *s = new StringNode();
					s->AddString(temp);
					for(int l_index = 0 ; l_index<26 ; l_index++)
					{
						s->m_Child[l_index] = m_Child[l_index];
						m_Child[l_index] = NULL;
					}

					m_Child[index] = s;
					isEndOfString = false;
				}

	
				//-----------------------------

				j=0;
				memset(temp,NULL,10);
				while(str[k] != NULL)
				{
					temp[j] = str[k]; 
					j++;
					k++;
				}

				if(temp[0]>=97 && temp[0]<=122)
				{
					index = temp[0] - 'a';
				}
				else if(temp[0]>=65 && temp[0]<=90)
				{
					index = temp[0] - 'A';
				}
				
				if(m_Child[index] == NULL)
				{
					m_Child[index] = new StringNode();
					printf("\n%d\t",index);
				}
	
				return (m_Child[index])->AddString(temp);
				
			}
		}
	}
}

bool StringNode :: DeleteString(char str[])
{
	int i=0;

	while(str[i] != NULL)
		{
			if(str[i] == m_String[i])
			{
				i++;
			}
			else
				break;
		}

	if(str[i] == NULL && m_String[i] == NULL)
	{
		if(isEndOfString == false)
		{
			return false;
		}
		else
		{
			int numberOfIndicesOccupied = 0;
			for(int l_index = 0 ; l_index<26 ; l_index++)
			{	
				if(m_Child[l_index] != NULL)
				{
					numberOfIndicesOccupied++;
				}
			}

			if(numberOfIndicesOccupied == 0)
			{
				flag = 1;
				return true;
			}	
			
			else if(numberOfIndicesOccupied == 1) 
			{
				flag = 2;
				return true;
			}
			else 
			{
				isEndOfString = false;
				return true;
			}
		}
	}

	else
	{
		if(m_String[i] != NULL && str[i] == NULL)
				return false;

		char temp[10];
		memset(temp,NULL,10);
		int j=0;

		while(str[i] != NULL)
		{
			temp[j] = str[i];
			i++;
			j++;
		}

		int index;
		if(temp[0]>=97 && temp[0]<=122)
		{
			index = temp[0] - 'a';
		}
		else if(temp[0]>=65 && temp[0]<=90)
		{
			index = temp[0] - 'A';
		}

		
		if(m_Child[index] == NULL)
		{
			return false;
		}

		bool isTrue = m_Child[index]->DeleteString(temp);
		
		if(isTrue == true && (flag == 1 || flag == 2))
		{
			if(flag == 1)
			{
				delete(m_Child[index]);
				m_Child[index] = NULL;
			}

			int numberOfIndicesOccupied = 0;
			for(int l_index = 0 ; l_index<26 ; l_index++)
			{	
				if(m_Child[l_index] != NULL)
				{
					numberOfIndicesOccupied++;
					index = l_index;
				}
			}
		

			if(numberOfIndicesOccupied == 1 && isEndOfString == false)
			{
				strcat(m_String,m_Child[index]->m_String);
				
				if(m_Child[index]->isEndOfString == true)
				{
					isEndOfString = true;
				}
				
				StringNode *s = new StringNode();
				
				for(int k=0 ; k<26 ; k++)
				{
					if(m_Child[index]->m_Child[k] != NULL)
						s->m_Child[k] = m_Child[index]->m_Child[k];
				}

				delete(m_Child[index]);

				for(int k=0 ; k<26 ; k++)
				{
					if(s->m_Child[k] != NULL)
						m_Child[k] = s->m_Child[k];
				}

				flag = 0;
				delete(s);
				return true;
			}
		}
	}
}

bool StringNode :: FindString(char str[])
{
	int i = 0;
	while(str[i] != NULL)
	{
		if(str[i] == m_String[i])
			i++;
		else
			break;
	}

	if(str[i] == NULL && m_String[i] == NULL)
	{
		if(isEndOfString == true)
			return true;
		else
			return false;
	}
	else if(m_String[i] != NULL && str[i] == NULL)
	{
		return false;
	}
	else
	{
		char temp[10];
		memset(temp,NULL,10);
		int j = 0;

		while(str[i] != NULL)
		{
			temp[j] = str[i];
			j++;
			i++;
		}

		int index;
		if(temp[0]>=97 && temp[0]<=122)
		{
			index = temp[0] - 'a';
		}
		else if(temp[0]>=65 && temp[0]<=90)
		{
			index = temp[0] - 'A';
		}
	
		if(m_Child[index] == NULL)
		{
			return false;
		}
	
		return (m_Child[index])->FindString(temp);
	}
}

void StringNode :: PrintString()
{
	if(isEndOfString == true)
	{
		printf("\n<SN value = \"%s\" flag = \"true\">",m_String);
	}
	else
	{
		printf("\n<SN value = \"%s\" flag = \"false\">",m_String);
	}

	for(int i=0; i<26 ;i++)
	{
		if(m_Child[i] != NULL)
		{
			(m_Child[i])->PrintString();
		}
	}
	printf("\n</SN>");
}


void main()
{
	TreeGate *TG = new TreeGate();
	TG->AddString("patpat");
	TG->AddString("pat");
	TG->AddString("patt");
	TG->AddString("patn");
	TG->AddString("pan");
	TG->AddString("and");

	printf("\n\n");
	printf("\n------------------------\n");
	//TG->PrintString();

	bool i = TG->FindString("pat");
	if(i == false)
	{
		printf("\nString not present in the tree");
	}
	else
	{	
		printf("\nString present in the tree");
	}
	printf("\n\n");
	printf("\n------------------------\n");

	TG->DeleteString("pat");
	i = TG->FindString("pat");
	if(i == false)
	{
		printf("\nString not present in the tree");
	}
	else
	{	
		printf("\nString present in the tree");
	}
	//TG->PrintString();
}