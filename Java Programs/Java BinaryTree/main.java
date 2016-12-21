
class main
{

   
  public static void main(String [] args)
  {

  BinaryTree<Integer> Tree = new BinaryTree<Integer>();

  Tree.addNode(3);
  Tree.addNode(5);
  Tree.addNode(6);
  Tree.addNode(3);
  Tree.addNode(2);
  Tree.addNode(10);

  Tree.inorder();
  Tree.deleteNode(10);
  Tree.deleteNode(5);
 //Tree.deleteNode(35)

  System.out.println("Modified Tree");
  Tree.inorder();



  }

}



