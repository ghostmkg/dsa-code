// LeetCode 102. Binary Tree Level Order Traversal

import java.util.ArrayList;
import java.util.List;
import java.util.LinkedList;
import java.util.Queue;

public class BinaryTreeLevelOrderTraversal {

    public class TreeNode {
       int val;
       TreeNode left;
       TreeNode right;
       TreeNode() {}
       TreeNode(int val) { this.val = val; }
       TreeNode(int val, TreeNode left, TreeNode right) {
           this.val = val;
           this.left = left;
           this.right = right;
       } 

    }

    public List<List<Integer>> levelOrder(TreeNode root) {
       List<List<Integer>> res=new ArrayList<>();
       if(root==null) return res;

       Queue<TreeNode> q=new LinkedList<>();
       q.add(root);
       TreeNode temp=null;

       while(!q.isEmpty()){
        int levelSize=q.size();
        List<Integer> inlist=new ArrayList<>();

        for(int i=0;i<levelSize;i++){
           temp=q.poll();
           inlist.add(temp.val);

           if (temp.left != null) q.add(temp.left);
           if (temp.right != null) q.add(temp.right);
        }
        res.add(inlist);
       } 

       return res;
    }
}

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000