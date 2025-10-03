// Time: O(m+n), Space: O(1)
var mergeTwoLists = function (list1, list2) {
  let dummy = { val: -1, next: null };
  let current = dummy;
  while (list1 && list2) {
    if (list1.val < list2.val) {
      current.next = list1;
      list1 = list1.next;
    } else {
      current.next = list2;
      list2 = list2.next;
    }
    current = current.next;
  }
  current.next = list1 || list2;
  return dummy.next;
};
