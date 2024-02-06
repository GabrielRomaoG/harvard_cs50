SELECT p.name
FROM movies m
JOIN people p
    ON p.id = s.person_id
JOIN stars s
    ON s.movie_id = m.id
WHERE
    m.id IN (
        SELECT m.id
        FROM movies m
        JOIN people p
            ON p.id = s.person_id
        JOIN stars s
            ON s.movie_id = m.id
        WHERE p.name = "Kevin Bacon" AND
        p.birth = 1958
    )
    AND p.name <> "Kevin Bacon"
;
