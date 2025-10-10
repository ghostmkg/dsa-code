<?php

class DisjointSet {
    private $parent = [];
    private $rank = [];

    public function __construct($n) {
        for ($i = 0; $i < $n; $i++) {
            $this->parent[$i] = $i;
            $this->rank[$i] = 0;
        }
    }

    public function find($x) {
        if ($this->parent[$x] != $x) {
            $this->parent[$x] = $this->find($this->parent[$x]); // Path compression
        }
        return $this->parent[$x];
    }

    public function union($x, $y) {
        $rootX = $this->find($x);
        $rootY = $this->find($y);

        if ($rootX == $rootY) return false;

        // Union by rank
        if ($this->rank[$rootX] < $this->rank[$rootY]) {
            $this->parent[$rootX] = $rootY;
        } elseif ($this->rank[$rootX] > $this->rank[$rootY]) {
            $this->parent[$rootY] = $rootX;
        } else {
            $this->parent[$rootY] = $rootX;
            $this->rank[$rootX]++;
        }

        return true;
    }
}

function kruskalMST($vertices, $edges) {
    // Sort edges by weight
    usort($edges, function($a, $b) {
        return $a[2] <=> $b[2];
    });

    $dsu = new DisjointSet($vertices);
    $mst = [];
    $totalWeight = 0;

    foreach ($edges as [$u, $v, $w]) {
        if ($dsu->union($u, $v)) {
            $mst[] = [$u, $v, $w];
            $totalWeight += $w;
        }
    }

    return [$mst, $totalWeight];
}

// Example Usage:
$vertices = 6;
$edges = [
    [0, 1, 4],
    [0, 2, 4],
    [1, 2, 2],
    [1, 0, 4],
    [2, 3, 3],
    [2, 5, 2],
    [2, 4, 4],
    [3, 4, 3],
    [5, 4, 3]
];

list($mst, $totalWeight) = kruskalMST($vertices, $edges);

echo "Edges in the Minimum Spanning Tree:\n";
foreach ($mst as [$u, $v, $w]) {
    echo "$u - $v : $w\n";
}
echo "Total weight of MST = $totalWeight\n";
