//Creating and searching for contacts in a phonebook using trie trees
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Alphabet size (# of symbols)
#define alphasize (26)
// Converts key current character into ind
// use only 'a' through 'z' and lower case
#define chartoind(c) ((int)c - (int)'a')
// creating a trie node
struct TrieNode
{
 struct TrieNode *children[alphasize];

 unsigned long long number;
 // is_end_of_word will be true if the node represents end of a word
 int is_end_of_word;
};
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
 struct TrieNode *node = NULL;
 node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
 if(node!=NULL)
 {
 int i;
 node->is_end_of_word = 0;
 for (i = 0; i < alphasize; i++)
 {
 node->children[i] = NULL;
 }
 }
 return node;
}
//Inserting a key into trie
// If not present, inserts key into trie
// If the key is prefix of trie node, just mark it the leaf node
void insert(struct TrieNode *root, const char *key)
{
 int level;
 int l = strlen(key);
 int ind;
 struct TrieNode *newnode = root;
 for (level = 0; level < l; level++)
 {
 ind = chartoind(key[level]);
 if (!newnode->children[ind])
 newnode->children[ind] = getNode();
 newnode = newnode->children[ind];
 }
 // mark the last node as leaf
 newnode->is_end_of_word = 1;
 printf("Enter the number:");
 scanf("%llu", &newnode->number);
}
int search(struct TrieNode *root, const char *key)
{
 int level;
 int length = strlen(key);
 int index;
 struct TrieNode *newnode = root;
 for (level = 0; level < length; level++)
 {
 index =chartoind(key[level]);
 if (!newnode->children[index])
 return 0;
 newnode=newnode->children[index];
 }
 return (newnode->is_end_of_word);
}
/*int duplicate(struct TrieNode *root,const char *key)
{
int j;
int len=strlen(key);
int ind;
 struct TrieNode *newnode = root;
 for (level = 0; level < l; level++)
 {
 ind = chartoind(key[level]);
 if (!newnode->children[ind])
 return 0;
 newnode = newnode->children[ind];
 }
}*/
// Main program to apply insert and search in a menu driven approach
int main()
{
int n1,i1,ch,hi;
char name[100];
char keys[100];
char output[][32] = {"Not present in Phonebook", "Present in
Phonebook"};
struct TrieNode *root;
root = getNode();
do
{
 printf("1.Create a New Contact\n2.Search For a Contact\n");
 printf("Please Enter Your Choice: ");
 scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the number of contacts to be updated in
PhoneBook:");
scanf("%d",&n1);
for(i1=0;i1<n1;i1++)
{
printf("Enter the name of the Person: ");
scanf("%s",keys);
//duplicate(root,keys);
insert(root, keys);
}
 break;
 case 2:
 printf("Enter the number of persons to be searched in
Phonebook: ");
 scanf("%d",&hi);

 for(i1=0;i1<hi;i1++)
 {
 printf("Enter the name to be Searched: ");
scanf("%s",name);
 printf("%s\n",output[search(root,name)]);
}
break;
default:
printf("Invalid Choice\n");
}
}while(ch<=2);
 return 0; }
