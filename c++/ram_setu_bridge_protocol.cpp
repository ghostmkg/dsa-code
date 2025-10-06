#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// --- Ram-Setu Bridge Protocol (RS-BP) Core Logic ---

// Structure to define a network link's state
struct LinkMetrics {
    double latency_ms;
    double failure_rate; // Probability of packet loss (0.0 to 1.0)
    double bandwidth;
};

// RS-BP utility function: Calculates the Resilience Score for a path segment.
// The score is inversely proportional to risk (high score = highly reliable/resilient).
double calculate_resilience_score(const LinkMetrics& link) {
    // Risk = (Failure Rate * 100) + (Latency / Bandwidth)
    // We want a high score, so we subtract risk from a large constant.
    
    double risk_penalty = (link.failure_rate * 100.0) + (link.latency_ms / link.bandwidth);
    
    // Max Score is 1000.0. Higher risk gives lower final score.
    return max(0.0, 1000.0 - risk_penalty);
}

// Function to find the best path out of a set of candidates
int select_best_path(const vector<LinkMetrics>& candidate_paths) {
    double best_score = -1.0;
    int best_index = -1;

    for (int i = 0; i < candidate_paths.size(); ++i) {
        double score = calculate_resilience_score(candidate_paths[i]);
        if (score > best_score) {
            best_score = score;
            best_index = i;
        }
    }
    return best_index;
}

// Example
int main() {
    // Define three paths currently available for routing a data shard
    vector<LinkMetrics> candidates = {
        // Path 0: Low latency, but moderate failure risk (The quick-sand path)
        {10.0, 0.05, 100.0}, 
        // Path 1: Higher latency, very low failure risk (The reliable stone path)
        {50.0, 0.01, 50.0},  
        // Path 2: High latency, high failure risk (The stormy path)
        {150.0, 0.15, 20.0} 
    };

    int chosen_path = select_best_path(candidates);
    
    cout << "--- Ram-Setu Bridge Protocol (RS-BP) Path Selection ---\n";
    cout << "Best Path Index Chosen: " << chosen_path << endl;
    cout << "Resilience Score: " << calculate_resilience_score(candidates[chosen_path]) << endl;
    cout << "Reason: Prioritizes stability (low failure rate) over raw speed.\n";

    return 0;
}