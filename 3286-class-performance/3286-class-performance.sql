# Write your MySQL query statement below
WITH TotalScores AS (
    SELECT student_id , (assignment1+assignment2+assignment3) AS total_score
    FROM Scores
)

SELECT MAX(total_score) - MIN(total_score) as difference_in_score
FROM TotalScores