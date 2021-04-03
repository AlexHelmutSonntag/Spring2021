public class SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode next;

    public SinglyLinkedListNode(int nodeData) {
        this.data = nodeData;
        this.next = null;
    }
    
    static SinglyLinkedListNode insertNodeAtPosition(SinglyLinkedListNode head, int data, int position) {

        SinglyLinkedListNode newNode = new SinglyLinkedListNode(data);
        SinglyLinkedListNode current = head;

        if (head == null) {
            newNode.next = null;
            return newNode;
        }
        if (position == 0) {
            newNode.next = head;
            return newNode;
        }

        int counter = 0;
        boolean flag = (current.next == null);
        while (counter < position - 1 && !flag) {
            current = current.next;
            counter++;
        }
        if (flag) {
            current.next = newNode;
            newNode.next = null;
            return head;
        }
        newNode.next = current.next;
        current.next = newNode;
        return head;

    }

    static SinglyLinkedListNode deleteNode(SinglyLinkedListNode head, int position) {

        if (position == 0) {
            return head.next;
        }

        head.next = deleteNode(head.next, position - 1);
        return head;

    }
}
