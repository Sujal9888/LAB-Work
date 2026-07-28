SELECT
    *
FROM
    books
WHERE
    released_year != 2017;

SELECT
    *
FROM
    books
WHERE
    title NOT LIKE '%e%';

SELECT
    *
FROM
    books
WHERE
    released_year > 2005;

SELECT
    *
FROM
    books
WHERE
    pages > 500;

SELECT
    *
FROM
    books
WHERE
    pages < 200;

SELECT
    *
FROM
    books
WHERE
    released_year < 2000;

SELECT
    *
FROM
    books
WHERE
    released_year <= 1985;

SELECT
    title,
    author_lname,
    released_year
FROM
    books
WHERE
    released_year > 2010
    AND author_lname = 'Eggers';

SELECT
    title,
    author_lname,
    released_year
FROM
    books
WHERE
    released_year > 2010
    AND author_lname = 'Eggers'
    AND title LIKE '%novel%';

SELECT
    title,
    pages
FROM
    books
WHERE
    len(title) > 30
    AND pages > 500;

SELECT
    title,
    author_lname
FROM
    books
WHERE
    author_lname = 'Eggers'
    AND released_year > 2010;

SELECT
    title,
    author_lname,
    released_year
FROM
    books
WHERE
    author_lname = 'Eggers'
    OR released_year > 2010;

SELECT
    title,
    pages
FROM
    books
WHERE
    pages < 200
    OR title LIKE '%stories%';

SELECT
    title,
    released_year
FROM
    books
WHERE
    released_year <= 2015
    AND released_year >= 2004;

SELECT
    title,
    released_year
FROM
    books
WHERE
    released_year BETWEEN 2004
    AND 2014;


SELECT
    title,
    author_lname
FROM
    books
WHERE
    author_lname = 'Carver'
    OR author_lname = 'Lahiri'
    OR author_lname = 'Smith';

SELECT
    title,
    author_lname
FROM
    books
WHERE
    author_lname IN ('Carver', 'Lahiri', 'Smith');

SELECT
    title,
    author_lname
FROM
    books
WHERE
    author_lname NOT IN ('Carver', 'Lahiri', 'Smith');

SELECT
    title,
    released_year
FROM
    books
WHERE
    released_year >= 2000
    AND released_year % 2 = 1;

SELECT
    title,
    released_year,
    CASE
        WHEN released_year >= 2000 THEN 'modern literature'
        ELSE '20th century literature'
    END AS genre
FROM
    books;

SELECT
    title,
    stock_quantity,
    CASE
        WHEN stock_quantity BETWEEN 0
        AND 40 THEN '*'
        WHEN stock_quantity BETWEEN 41
        AND 70 THEN '**'
        WHEN stock_quantity BETWEEN 71
        AND 100 THEN '***'
        WHEN stock_quantity BETWEEN 101
        AND 140 THEN '****'
        ELSE '*****'
    END AS stock
FROM
    books;

SELECT
    title,
    stock_quantity,
    CASE
        WHEN stock_quantity <= 40 THEN '*'
        WHEN stock_quantity <= 70 THEN '**'
        WHEN stock_quantity <= 100 THEN '***'
        WHEN stock_quantity <= 140 THEN '****'
        ELSE '*****'
    END AS stock
FROM
    books;

SELECT
    *
FROM
    books
WHERE
    released_year < 1980;

SELECT
    *
FROM
    books
WHERE
    author_lname = 'Eggers'
    OR author_lname = 'Chabon';

SELECT
    *
FROM
    books
WHERE
    author_lname = 'Lahiri'
    AND released_year > 2000;

SELECT
    *
FROM
    books
WHERE
    pages >= 100
    AND pages <= 200;

SELECT
    *
FROM
    books
WHERE
    pages BETWEEN 100
    and 200;

SELECT
    title,
    author_lname
FROM
    books
WHERE
    author_lname LIKE 'C%'
    OR author_lname LIKE 'S%';

SELECT
    title,
    author_lname
FROM
    books
WHERE
    SUBSTRING(author_lname, 1, 1) in ('C', 'S');

SELECT
    title,
    author_lname,
    CASE
        WHEN title LIKE '%stories%' THEN 'Short Stories'
        WHEN title = 'Just Kids' THEN 'Memoir'
        WHEN title = 'A Heartbreaking Work of Staggering Genius' THEN 'Memior'
        ELSE 'Novel'
    END AS type
FROM
    books;

SELECT
    author_fname,
    author_lname,
    CASE
        WHEN COUNT(*) = 1 THEN '1 book'
        ELSE CONCAT(COUNT(*), ' books')
    END AS count
FROM
    books
WHERE
    author_lname IS NOT NULL
GROUP BY
    author_fname,
    author_lname;
