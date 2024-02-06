SELECT m.title
FROM movies m
JOIN people p
    ON p.id = s.person_id
JOIN stars s
    ON s.movie_id = m.id
WHERE
    p.name IN ("Bradley Cooper", "Jennifer Lawrence")
GROUP BY m.title
HAVING COUNT(*) = 2
;
