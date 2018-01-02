class BinaryTree <E extends Comparable<E>>
{

 private Node<E> root;

 public BinaryTree()
 {
   root = null;
 }

 public Node<E> getRoot()
 {
   return root;
 }

 public void addNode(E input)
 {

  Node<E> newnode = new Node<E>();
  newnode.value = input;
  newnode.right = null;
  newnode.left = null;

  root = insertNode(root, newnode);
 }

 //returning everything to keep track of the root
 // The tree will construct by using a copy of the root and a copy of newnode. The reason the tree works is because the Tree is constructed, and returned in a manner in which 
 // the trees root is kept track of and the root of the tree will be returned, making the root of the original bst assigned the tree's root. 
 private Node<E> insertNode(Node<E> currentParent, Node<E> newnode)
 {
   if (currentParent == null)
   return newnode;

   else if (newnode.value.compareTo(currentParent.value) < 0)
   currentParent.left = insertNode(currentParent.left, newnode);
 
   else
   currentParent.right = insertNode(currentParent.right, newnode);

  return currentParent;
 }

/*
 public boolean insertNode(E input)
 {
   if (root == null)
   {
     Node<E> newnode = new Node();
     newnode.value = input;
     newnode.right = null;
     newnode.left = null;
     
     root = newnode;
   }

  Node<E> parent = null;
  Node<E> current = root;

 while (current != null)
 {
   if (input.compareTo(current.value) < 0)
   {
     parent = current;
     current = current.left;
   }
   else if (input.compareTo(current.value) > 0)
   {
     parent = current;
     current = current.right;
   }
   else
   return false;
 }

  if (input.compareTo(parent.value) < 0)
  {
    Node<E> newnode = new Node();
    newnode.value = input;
    newnode.right = null;
    newnode.left = null;
     
     parent.left = newnode;
  }
  
  else
  {
    Node<E> newnode = new Node();
    newnode.value = input;
    newnode.right = null;
    newnode.left = null;
     
     parent.right = newnode;
  }

return true;
}
*/
 public void inorder()
 {
   inordertraversal(getRoot());
 }

 private void inordertraversal(Node<E> root)
 {
   if (root == null)
   return;
   inordertraversal(root.left);
   System.out.println(root.value);
   inordertraversal(root.right);
 }

 public void deleteNode(E input)
 {

   Node<E> current = root;
   Node<E> parent = null;
   boolean flag = findNode(input, root);

   if (flag == false)
   {
     System.out.println(input + " is not in the tree");
     return;
   }

   else
   {
	while(current != null)
        {
          if ((current.value).compareTo(input) < 0)
          {
	    parent = current;
	    current = current.right;
          }

          else if ((current.value).compareTo(input) > 0)
          {
            parent = current;
            current = current.left;
          }

          else if (current.value == input)
          break;
         }
    }

 if (current.left == null)
 {
   if (parent == null)
   parent = current.right;

   else
   {
     if (input.compareTo(parent.value) > 0)
     parent.right = current.right;
     else
     parent.left = current.right;
   }
 }

 else
 {
   Node<E> parentOfRightMost = current;
   Node<E> rightMost = current.left;

   while(rightMost.right != null)
   {
	parentOfRightMost = rightMost;
	rightMost = rightMost.right;
   }

   current.value = rightMost.value;

   if (parentOfRightMost.right == rightMost)
   {
	parentOfRightMost.right = rightMost.left;
   }

   else
   {
     parentOfRightMost.left = rightMost.left;
   }
 }
}

 public boolean findNode(E input, Node<E> root)
 {
   while (root != null)
   { 
     if (root.value == input)
     {
    	return true;
     }
     else if (input.compareTo(root.value) > 0)
     {
      root = root.right;
     }
     else
     {
     root = root.left;
     }
  }

  return false;
 }

 /*
 //recursion didnt work for some reason????
 //kept "missing return statement" for no reason?????
 public boolean findNode(E input, Node<E> root)
 {
  if (root != null)
  { 
     if (root.value == input)
     {
    	return true;
     }

     else if (input.compareTo(root.value) > 0)
     {
     findNode(input, root.right);
     }
     else
     {
     findNode(input, root.left);
     }
  }

  else
  return false;
 }
*/
}
