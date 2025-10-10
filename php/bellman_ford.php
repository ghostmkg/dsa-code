<?php

function bellmanFord($vertices, $edges, $src) {
    // Step 1: Initialize distances
    $dist = array_fill(0, $vertices, INF);
    $dist[$src] = 0;

    // Step 2: Relax edges |V| - 1 times
    for ($i = 0; $i < $vertices - 1; $i++) {
        $updated = false;
        foreach ($edges as [$u, $v, $w]) {
            if ($dist[$u] != INF && $dist[$u] + $w < $dist[$v]) {
                $dist[$v] = $dist[$u] + $w;
                $updated = true;
            }
        }
        if (!$updated) break; // Optimization: stop if no change
    }

    // Step 3: Check for negative-weight cycles
    foreach ($edges as [$u, $v, $w]) {
        if ($dist[$u] != INF && $dist[$u] + $w < $dist[$v]) {
            echo "Graph contains a negative weight cycle!\n";
            return null;
        }
    }

    return $dist;
}

// Example graph
$vertices = 5;
$edges = [
    [0, 1, -1],
    [0, 2, 4],
    [1, 2, 3],
    [1, 3, 2],
    [1, 4, 2],
    [3, 2, 5],
    [3, 1, 1],
    [4, 3, -3]
];

$src = 0;
$distances = bellmanFord($vertices, $edges, $src);

if ($distances !== null) {
    echo "Vertex\tDistance from Source ($src)\n";
    foreach ($distances as $i => $d) {
        $dStr = ($d == INF) ? "∞" : $d;
        echo "$i\t$dStr\n";
    }
}
