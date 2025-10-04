#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;



//program to print smallest node at each level of a binary tree

struct BinaryTreeNode{
	int data;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};



//function to find smallest element in a vector
int smallest(vector<int> &v)
{
	vector<int>::iterator i;
	int small = v[0];
	
	for(i = v.begin(); i != v.end() ; i++ )
	{
		if( *i < small )
		{
			small = *i;	
		}	
	}
	
	return small;
}


//function to store all the nodes at each level in a hash map
void SmallestNodeUtil(BinaryTreeNode *root, map< int,vector<int> > &Map ,int level)
{
	if(!root) return;
	
	
	
	//store each level as key and corresponding elements at that level in a vector
	SmallestNodeUtil(root->left,Map,level+1);
	
	//storing all nodes at each same level in hash map
	Map[level].push_back(root->data);
	
	SmallestNodeUtil(root->right,Map,level+1);
	
}


void SmallestNode(BinaryTreeNode *root)
{
	map< int,vector<int> > Map;
	map<int,vector<int> >::iterator it;
	
	//populating the map
	SmallestNodeUtil(root,Map,0);
	
	cout<<"level "<<" "<<" Smallest Node"<<endl;
	
	for(it = Map.begin() ; it!=Map.end() ; it++)
	{
		
		cout<<       it->first<<"   |    ";
		
//		cout<<*min_element(it->second.begin(),it->second.end());
		//or use custom function to find minimum element
		cout<<smallest(it->second);
		 //finding smallest at that level	
	
		
		cout<<endl;
	}
	
}



//Approach B-using iterative level order traversal

void SmallestLevelNodeUsingLevelOrder(BinaryTreeNode *root)
{
	queue<BinaryTreeNode *>q;
	BinaryTreeNode *temp;
	if(!root) return;
	
	int min = INT_MAX;
	
	int level=0;
	q.push(root);
	q.push(NULL); //marker for completion of level-0
	
	
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		
		if(temp==NULL)
		{
			cout<<"At level "<<level<<" minimum node is "<<min<<endl;
			
			if(q.empty()) break;
			
			q.push(NULL);
			
			level++;
			
			//resetting min for next level's minimum value
			min = INT_MAX;
			
			continue;
		}
		
		
		//get minimum at every level
		if(min > temp->data)
		{
			
			min = temp->data;
			
		}
		
		
		if(temp->left) q.push(temp->left);
		if(temp->right) q.push(temp->right);
		
	}
}


void Insert( struct BinaryTreeNode **root,int data)
{
	struct BinaryTreeNode *new_node = new BinaryTreeNode();
	struct BinaryTreeNode *temp;
	queue<BinaryTreeNode *> q;
	new_node->data = data;
	new_node->left=NULL;
	new_node->right=NULL;
	
	if(*root==NULL)
	{
		*root = new_node;
		return;
	}
	
	q.push(*root);
	
	while(!q.empty())
	{
		temp  = q.front();
		q.pop();
		
		if(temp->left==NULL)
		{
			temp->left = new_node;
			return;
			
			
		}
		
		else
		{
			q.push(temp->left);
		}
			
		if(temp->right==NULL)
		{
			temp->right = new_node;
			return;
			
		}	
		
		else
		{
			q.push(temp->right);
		}
	}
	
	
}



int main()
{
	struct BinaryTreeNode *root1= NULL;
	
	Insert(&root1,7);
	Insert(&root1,6);
	Insert(&root1,5);
	Insert(&root1,4);
	Insert(&root1,3);
	Insert(&root1,2);
	Insert(&root1,1);
//	Insert(&root1,11);
//	Insert(&root1,-1);
	
		
	
	
//	SmallestNode(root1);
	
	SmallestLevelNodeUsingLevelOrder(root1);	
	
	
	return 0;
}
