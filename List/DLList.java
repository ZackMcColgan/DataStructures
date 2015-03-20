
/**
 * Linked list
 * @author Zack McColgan 
 * This class creates a doubly linked list
 */
public class DLList
{

    public class DNode
    {

        public int info;
        public DNode next = null, prev = null;

        DNode()
        {
        }

        DNode(int el)
        {
            info = el;
        }
    }

    private DNode head, tail;

    public DLList()
    {
        head = tail = null;
    }

  
    /**
     * Add a new node to the tail of the list
     *
     * @param num the number to add to the list
     */
    public void addToTail(int num)
    {
        if (head == null)  // If the list is empty
        {
            DNode node = new DNode(num);
            head = node;
            tail = node;
        } else
        {
            DNode node = new DNode(num);
            tail.next = node;
            node.prev = tail;
            tail = node;
        }
    }

    /**
     * Prints the list starting with the head
     */
    public void printList()
    {
        if (head == null)
        {
            System.out.println("The list is empty!");
        } else
        {
            DNode temp = head;
            while (temp != null)
            {
                System.out.print(temp.info + " ");
                temp = temp.next;
            }
            System.out.println();
        }
    }

    /**
     * Searches then deletes a specified node from the list
     *
     * @param num the number to search for
     */
    public void delete(int num)
    {
        if (head == null)   // If the list is empty
        {
            System.out.println("The list is empty!");
        } else
        {
            DNode temp = head;

            if (head.next == null) // If there is only one node
            {
                head = null;
                tail = null;
                return;
            }

            while (temp != null)  // Moves through the list looking for the num
            {
                if (temp.info == num)  // Found the number
                {
                    if (temp.prev == null)  // If you are deleting the head
                    {
                        head = temp.next;
                        temp.next.prev = null;
                        return;
                    }
                    if (temp.next != null && temp.prev != null)   // If the node is in the middle
                    {
                        temp.prev.next = temp.next;
                        temp.next.prev = temp.prev;
                        return;
                    }
                    if (temp.next == null)  // If the node is the tail
                    {
                        tail = temp.prev;
                        tail.next = null;
                        return;
                    }

                }
                temp = temp.next;
            }
        }
    }

}
