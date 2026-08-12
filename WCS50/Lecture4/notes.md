# SQL, Models and Migrations

## SQL - Structured Query Language
- Relational databases where data is stored in tables with a set number of columns and a variable number os rows.
- Other different relational database management systems that are commonly used to store information, and that can easily interact with SQL commands:
    - MySQL and PostgreSQL: heavier-duty databases typically run on servers separate from those running a website
    - MongoDB, DynamoDB: non-relational database  
    - SQLite: lighter-weight system that can store all of its data in a single file -> we'll use this one for now

### SQLite Column Types
- TEXT: strings
- NUMERIC: general for numeric data (bool, data, etc)
- INTEGER: non-decimals
- REAL: real numbers i.e decimals
- BLOB: Binary Large Objects (images or binary data in general)

OBS.: each database will have its variation of these! SQLite is the simplest one.

### Table Queries
```
CREATE TABLE flights(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    origin TEXT NOT NULL,
    destination TEXT NOT NULL,
    duration INTEGER NOT NULL
);
``` 
- `id`: name for this var
- `integer`, `text`: type of the var
-`autoincrement`: means we will not have to provide an id every time we add to the table because it will be done automatically
- `primary key`, `not null`: constraints -> keywords that define the behavior of a var

Some constraints:
- CHECK: Makes sure certain constraints are met before allowing a row to be added/modified
- DEFAULT: Provides a default value if no value is given
- NOT NULL: Makes sure a value is provided
- PRIMARY KEY: Indicates this is the primary way of searching for a row in the database
- UNIQUE: Ensures that no two rows have the same value in that column.

```
INSERT INTO flights
    (origin, destination, duration)
    VALUES ("New York", "London", 415);
```

```
SELECT * FROM flights;
```
- this query is used to retrieve information from an existing table
- using * means we'll get all of the info on the table
- instead we can use `SELECT origin, destination FROM flights;` to select those two specific columns
- to select specific rows: `SELECT * FROM flights WHERE id = 3;`, which will select the third row
- to select all of the rows that have a specific value: `SELECT * FROM flights WHERE origin = "New York";`

### Terminal Commands for SQL

- `New-Item flights.sql` to create a new database.
- `sqlite3 db.sqlite3 ".tables"` 