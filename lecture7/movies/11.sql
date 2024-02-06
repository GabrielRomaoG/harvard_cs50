SELECT m.title
FROM people p
JOIN stars s
    ON s.person_id = p.id
JOIN movies m
    ON m.id = s.movie_id
JOIN ratings r
    ON r.movie_id = m.id
WHERE p.name = "Chadwick Boseman"
ORDER BY r.rating DESC
LIMIT 5
;
