// MergeTwoLists.java
public class mergeTwoLists {

    // Definition for singly-linked list node.
    static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    // Iterative approach: merges two sorted lists and returns the head of the merged list.
    public static ListNode mergeTwoListsIterative(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1); // dummy head
        ListNode tail = dummy;

        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        // attach remaining nodes
        tail.next = (l1 != null) ? l1 : l2;

        return dummy.next;
    }

    // Recursive approach: merges two sorted lists (clean and concise).
    public static ListNode mergeTwoListsRecursive(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;

        if (l1.val <= l2.val) {
            l1.next = mergeTwoListsRecursive(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoListsRecursive(l1, l2.next);
            return l2;
        }
    }

    // Helper: build linked list from array, returns head.
    public static ListNode buildList(int[] arr) {
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        for (int v : arr) {
            tail.next = new ListNode(v);
            tail = tail.next;
        }
        return dummy.next;
    }

    // Helper: print linked list.
    public static void printList(ListNode head) {
        ListNode cur = head;
        while (cur != null) {
            System.out.print(cur.val);
            if (cur.next != null) System.out.print(" -> ");
            cur = cur.next;
        }
        System.out.println();
    }

    // Example usage and simple tests.
    public static void main(String[] args) {
        // Example 1
        int[] a1 = {1, 2, 4};
        int[] b1 = {1, 3, 4};
        ListNode l1 = buildList(a1);
        ListNode l2 = buildList(b1);

        System.out.print("List A: ");
        printList(l1);
        System.out.print("List B: ");
        printList(l2);

        ListNode mergedIter = mergeTwoListsIterative(l1, l2);
        System.out.print("Merged (iterative): ");
        printList(mergedIter);

        // For recursive test, recreate lists (previous merge re-used nodes).
        l1 = buildList(a1);
        l2 = buildList(b1);
        ListNode mergedRec = mergeTwoListsRecursive(l1, l2);
        System.out.print("Merged (recursive): ");
        printList(mergedRec);

        // Example 2: one list empty
        ListNode empty = null;
        ListNode single = buildList(new int[]{0});
        System.out.print("Merged (one empty): ");
        printList(mergeTwoListsIterative(empty, single));
    }
}
