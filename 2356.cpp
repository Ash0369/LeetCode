SELECT teacher_id,COUNT(DISTINCT(SUBJECT_ID)) as cnt
FROM Teacher
GROUP BY teacher_id
