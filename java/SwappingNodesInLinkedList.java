/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
// contributor > Ayaaz Qureshi
// guthub>> AyaazQureshi
class Solution {
    public ListNode swapNodes(ListNode head, int k) {
        if (head == null || head.next == null) return head;

        ListNode first = head;
        for (int i = 1; i < k; i++) {
            first = first.next;
        }

        ListNode temp = head;
        int len = 0;
        while (temp != null) {
            temp = temp.next;
            len++;
        }

        ListNode second = head;
        for (int i = 1; i <= len - k; i++) {
            second = second.next;
        }

        // Swap values
        int t = first.val;
        first.val = second.val;
        second.val = t;

        return head;
    }
}