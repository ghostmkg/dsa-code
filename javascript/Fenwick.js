class FenwickTree {
  constructor(size) {
    this.tree = new Array(size + 1).fill(0);
    this.size = size;
  }

  update(i, delta) {
    i++;
    while (i <= this.size) {
      this.tree[i] += delta;
      i += i & -i;
    }
  }

  query(i) {
    i++;
    let sum = 0;
    while (i > 0) {
      sum += this.tree[i];
      i -= i & -i;
    }
    return sum;
  }

  rangeQuery(l, r) {
    if (l > r) return 0;
    return this.query(r) - this.query(l - 1);
  }

  build(arr) {
    for (let i = 0; i < arr.length; i++) {
      this.update(i, arr[i]);
    }
  }
}
