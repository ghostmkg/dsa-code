use std::collections::HashMap;

/// Calculate entropy of a dataset
fn entropy(labels: &Vec<String>) -> f64 {
    let mut counts = HashMap::new();
    for label in labels {
        *counts.entry(label).or_insert(0) += 1;
    }

    let total = labels.len() as f64;
    let mut ent = 0.0;

    for count in counts.values() {
        let p = *count as f64 / total;
        ent -= p * p.log2();
    }

    ent
}

/// Structure representing a dataset
#[derive(Debug, Clone)]
struct Dataset {
    features: Vec<Vec<f64>>,
    labels: Vec<String>,
}

/// A Decision Tree Node
#[derive(Debug)]
enum Node {
    Leaf(String),
    Decision {
        feature_index: usize,
        threshold: f64,
        left: Box<Node>,
        right: Box<Node>,
    },
}

/// Split dataset based on a feature threshold
fn split_dataset(dataset: &Dataset, feature_index: usize, threshold: f64) -> (Dataset, Dataset) {
    let mut left_features = vec![];
    let mut left_labels = vec![];
    let mut right_features = vec![];
    let mut right_labels = vec![];

    for i in 0..dataset.features.len() {
        if dataset.features[i][feature_index] <= threshold {
            left_features.push(dataset.features[i].clone());
            left_labels.push(dataset.labels[i].clone());
        } else {
            right_features.push(dataset.features[i].clone());
            right_labels.push(dataset.labels[i].clone());
        }
    }

    (
        Dataset { features: left_features, labels: left_labels },
        Dataset { features: right_features, labels: right_labels },
    )
}

/// Build the decision tree recursively
fn build_tree(dataset: &Dataset, depth: usize) -> Node {
    if depth == 0 || dataset.labels.iter().all(|x| *x == dataset.labels[0]) {
        // Leaf node
        return Node::Leaf(dataset.labels[0].clone());
    }

    let mut best_gain = 0.0;
    let mut best_feature = 0;
    let mut best_threshold = 0.0;
    let current_entropy = entropy(&dataset.labels);

    for feature_index in 0..dataset.features[0].len() {
        for sample in &dataset.features {
            let threshold = sample[feature_index];
            let (left, right) = split_dataset(dataset, feature_index, threshold);

            if left.labels.is_empty() || right.labels.is_empty() {
                continue;
            }

            let p_left = left.labels.len() as f64 / dataset.labels.len() as f64;
            let gain = current_entropy
                - (p_left * entropy(&left.labels) + (1.0 - p_left) * entropy(&right.labels));

            if gain > best_gain {
                best_gain = gain;
                best_feature = feature_index;
                best_threshold = threshold;
            }
        }
    }

    if best_gain == 0.0 {
        return Node::Leaf(dataset.labels[0].clone());
    }

    let (left, right) = split_dataset(dataset, best_feature, best_threshold);
    Node::Decision {
        feature_index: best_feature,
        threshold: best_threshold,
        left: Box::new(build_tree(&left, depth - 1)),
        right: Box::new(build_tree(&right, depth - 1)),
    }
}

/// Predict the label for a given sample
fn predict(node: &Node, sample: &Vec<f64>) -> String {
    match node {
        Node::Leaf(label) => label.clone(),
        Node::Decision { feature_index, threshold, left, right } => {
            if sample[*feature_index] <= *threshold {
                predict(left, sample)
            } else {
                predict(right, sample)
            }
        }
    }
}

fn main() {
    let dataset = Dataset {
        features: vec![
            vec![2.0, 3.0],
            vec![1.0, 5.0],
            vec![3.0, 2.0],
            vec![5.0, 1.0],
        ],
        labels: vec![
            "A".to_string(),
            "A".to_string(),
            "B".to_string(),
            "B".to_string(),
        ],
    };

    let tree = build_tree(&dataset, 3);
    println!("Trained Tree: {:#?}", tree);

    let test_sample = vec![2.5, 3.0];
    let prediction = predict(&tree, &test_sample);
    println!("Prediction for {:?}: {}", test_sample, prediction);
}
