DROP DATABASE IF EXISTS day2;

create database day2;
use day2;

DROP TABLE IF EXISTS books;

CREATE TABLE books (
    book_id INT IDENTITY(1,1) PRIMARY KEY,
    title VARCHAR(100),
    author_fname VARCHAR(100),
    author_lname VARCHAR(100),
    released_year INT,
    stock_quantity INT,
    pages INT
);

INSERT INTO
    books (
        title,
        author_fname,
        author_lname,
        released_year,
        stock_quantity,
        pages
    )
VALUES
    (
        'The Namesake',
        'Jhumpa',
        'Lahiri',
        2003,
        32,
        291
    ),
    (
        'Norse Mythology',
        'Neil',
        'Gaiman',
        2016,
        43,
        304
    ),
    ('American Gods', 'Neil', 'Gaiman', 2001, 12, 465),
    (
        'Interpreter of Maladies',
        'Jhumpa',
        'Lahiri',
        1996,
        97,
        198
    ),
    (
        'A Hologram for the King: A Novel',
        'Dave',
        'Eggers',
        2012,
        154,
        352
    ),
    ('The Circle', 'Dave', 'Eggers', 2013, 26, 504),
    (
        'The Amazing Adventures of Kavalier & Clay',
        'Michael',
        'Chabon',
        2000,
        68,
        634
    ),
    ('Just Kids', 'Patti', 'Smith', 2010, 55, 304),
    (
        'A Heartbreaking Work of Staggering Genius',
        'Dave',
        'Eggers',
        2001,
        104,
        437
    ),
    ('Coraline', 'Neil', 'Gaiman', 2003, 100, 208),
    (
        'What We Talk About When We Talk About Love: Stories',
        'Raymond',
        'Carver',
        1981,
        23,
        176
    ),
    (
        'Where I''m Calling From: Selected Stories',
        'Raymond',
        'Carver',
        1989,
        12,
        526
    ),
    ('White Noise', 'Don', 'DeLillo', 1985, 49, 320),
    (
        'Cannery Row',
        'John',
        'Steinbeck',
        1945,
        95,
        181
    ),
    (
        'Oblivion: Stories',
        'David',
        'Foster Wallace',
        2004,
        172,
        329
    ),
    (
        'Consider the Lobster',
        'David',
        'Foster Wallace',
        2005,
        92,
        343
    );

select * from books;

SELECT
    COUNT(*)
FROM
    books;

SELECT
    COUNT(author_lname)
FROM
    books;

SELECT
    COUNT(DISTINCT author_lname)
FROM
    books;

SELECT
    author_lname,
    COUNT(*) as books_written
FROM
    books
GROUP BY
    author_lname;

SELECT
    author_lname,
    COUNT(*) AS books_written
FROM
    books
GROUP BY
    author_lname
ORDER BY
    books_written DESC;

select * from books;

SELECT
    MAX(pages) as max_pages
FROM
    books;


SELECT
    title,
    pages
FROM
    books
WHERE
    pages = (
        SELECT
            MAX(pages)
        FROM
            books
    );

SELECT
    MIN(released_year)
FROM
    books;

SELECT
    title,
    released_year
FROM
    books
WHERE
    released_year = (
        SELECT
            MIN(released_year)
        FROM
            books
    );

SELECT
    author_fname,
    author_lname,
    COUNT(*)
FROM
    books
GROUP BY
    author_lname,
    author_fname;

SELECT
    CONCAT(author_fname, ' ', author_lname) AS author,
    COUNT(*)
FROM
    books
GROUP BY
    CONCAT(author_fname, ' ', author_lname);

SELECT
    author_lname,
    MIN(released_year)
FROM
    books
GROUP BY
    author_lname;

SELECT
    author_lname,
    MAX(released_year),
    MIN(released_year)
FROM
    books
GROUP BY
    author_lname;

SELECT
    author_lname,
    COUNT(*) as books_written,
    MAX(released_year) AS latest_release,
    MIN(released_year) AS earliest_release,
    MAX(pages) AS longest_page_count
FROM
    books
GROUP BY
    author_lname;

SELECT
    author_lname,
    author_fname,
    COUNT(*) as books_written,
    MAX(released_year) AS latest_release,
    MIN(released_year) AS earliest_release
FROM
    books
GROUP BY
    author_lname,
    author_fname;

SELECT
    SUM(pages)
FROM
    books;

SELECT
    author_lname,
    COUNT(*),
    SUM(pages)
FROM
    books
GROUP BY
    author_lname;

SELECT
    AVG(pages)
FROM
    books;

SELECT
    AVG(released_year)
FROM
    books;

SELECT
    released_year,
    AVG(stock_quantity),
    COUNT(*)
FROM
    books
GROUP BY
    released_year;

SELECT
    COUNT(*)
FROM
    books;

SELECT
    released_year,
    COUNT(*)
FROM
    books
GROUP BY
    released_year;

SELECT
    AVG(released_year)
FROM
    books
GROUP BY
    author_lname,
    author_fname;

SELECT
    CONCAT(author_fname, ' ', author_lname) AS author,
    pages
FROM
    books
WHERE
    pages = (
        SELECT
            MAX(pages)
        FROM
            books
    );