#include <array>
#include <string>
#include <vector>
// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // Implement round_down_scores
    std::vector<int> rd_scores {};
    for (double score : student_scores){
        rd_scores.push_back(static_cast<int>(score));
    }
    return rd_scores;
}
// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for (int score : student_scores){
        if (score <= 40) count++;
    }
    return count;
}
// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // Using integer division ((highest_score - 40) / 4) automatically rounds down to the nearest integer step size per the exercise specification.
    int step = (highest_score - 40) / 4;
    return {41, 41 + step, 41 + step*2, 41 + step*3};
}
// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> rank;
    for (size_t i = 0; i < student_scores.size(); ++i){
        int ranking = i + 1;
        rank.push_back(std::to_string(ranking) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }
    return rank;
}
// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    for (std::size_t i = 0; i < student_scores.size() ; i++){
        if (student_scores[i] == 100) return student_names[i];// Stops and returns the name immediately
    }
    
    return "";
}
