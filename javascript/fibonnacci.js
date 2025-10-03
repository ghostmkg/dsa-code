function fibonacciSeries(n) {
  const series = [];
  let a = 0,
    b = 1;

  for (let i = 0; i < n; i++) {
    series.push(a);
    [a, b] = [b, a + b];
  }

  return series;
}
