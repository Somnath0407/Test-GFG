/*
class Node
{
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}

*/
class Solution {
    // Helper method to perform inorder traversal and store in list
    private void inorder(Node root, ArrayList<Integer> list) {
        if (root == null) return;

        inorder(root.left, list);
        list.add(root.data);
        inorder(root.right, list);
    }

    // Function to merge two BSTs and return sorted list
    public ArrayList<Integer> merge(Node root1, Node root2) {
        ArrayList<Integer> list1 = new ArrayList<>();
        ArrayList<Integer> list2 = new ArrayList<>();

        inorder(root1, list1);
        inorder(root2, list2);

        // Merge two sorted lists
        ArrayList<Integer> merged = new ArrayList<>();
        int i = 0, j = 0;

        while (i < list1.size() && j < list2.size()) {
            if (list1.get(i) < list2.get(j)) {
                merged.add(list1.get(i++));
            } else {
                merged.add(list2.get(j++));
            }
        }

        // Add remaining elements
        while (i < list1.size()) {
            merged.add(list1.get(i++));
        }
        while (j < list2.size()) {
            merged.add(list2.get(j++));
        }

        return merged;
    }
}
