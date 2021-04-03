public class DoublyLinkedListNode {
    public int data;
    public DoublyLinkedListNode next;
    public DoublyLinkedListNode prev;

    public DoublyLinkedListNode(int nodeData) {
        this.data = nodeData;
        this.next = null;
        this.prev = null;
    }

    static DoublyLinkedListNode sortedInsert(DoublyLinkedListNode head, int data) {

        DoublyLinkedListNode newNode = new DoublyLinkedListNode(data);
        DoublyLinkedListNode currentNode = head;

        if (head == null) {
            return newNode;
        }
        if (newNode.data < head.data) {
            newNode.next = head;
            head.prev = newNode;
            return newNode;
        }

        else {
            DoublyLinkedListNode rest = sortedInsert(currentNode.next, data);
            currentNode.next = rest;
            rest.prev = currentNode;
            return head;

        }

    }

}
