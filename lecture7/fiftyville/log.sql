-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT c.*
FROM crime_scene_reports c
WHERE
    c.day = 28 AND
    c.month = 7 AND
    c.year = 2023 AND
    c.street = 'Humphrey Street'
;

/*
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 295 | 2023 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
| 297 | 2023 | 7     | 28  | Humphrey Street | Littering took place at 16:36. No known witnesses.                                                                                                                                                                       |
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
*/

-- crime_id: 295
-- description:
    -- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
    -- Interviews were conducted today with three witnesses who were present at the time –
    -- each of their interview transcripts mentions the bakery.
-- 10:15 am
-- three witness
-- bakery


-------------------------------------------------------------------------------------------------------------------

SELECT s.*
FROM bakery_security_logs s
WHERE
    s.day = 28 AND
    s.month = 7 AND
    s.year = 2023 AND
    s.hour = 10
;

/*
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 258 | 2023 | 7     | 28  | 10   | 8      | entrance | R3G7486       |
| 259 | 2023 | 7     | 28  | 10   | 14     | entrance | 13FNH73       |
| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
| 268 | 2023 | 7     | 28  | 10   | 35     | exit     | 1106N58       |
| 269 | 2023 | 7     | 28  | 10   | 42     | entrance | NRYN856       |
| 270 | 2023 | 7     | 28  | 10   | 44     | entrance | WD5M8I6       |
| 271 | 2023 | 7     | 28  | 10   | 55     | entrance | V47T75I       |
+-----+------+-------+-----+------+--------+----------+---------------+

Possible suspect license's plate - Ruth statement

| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
*/



--------------------------------------------------------------------------------------------

SELECT *
FROM interviews i
WHERE
    i.day = 28 AND
    i.month = 7 AND
    i.year = 2023
;

/*
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| id  |  name   | year | month | day |                                                                                                                                                     transcript                                                                                                                                                      |
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 158 | Jose    | 2023 | 7     | 28  | “Ah,” said he, “I forgot that I had not seen you for some weeks. It is a little souvenir from the King of Bohemia in return for my assistance in the case of the Irene Adler papers.”                                                                                                                               |
| 159 | Eugene  | 2023 | 7     | 28  | “I suppose,” said Holmes, “that when Mr. Windibank came back from France he was very annoyed at your having gone to the ball.”                                                                                                                                                                                      |
| 160 | Barbara | 2023 | 7     | 28  | “You had my note?” he asked with a deep harsh voice and a strongly marked German accent. “I told you that I would call.” He looked from one to the other of us, as if uncertain which to address.                                                                                                                   |
| 161 | Ruth    | 2023 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | 2023 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | 2023 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
| 191 | Lily    | 2023 | 7     | 28  | Our neighboring courthouse has a very annoying rooster that crows loudly at 6am every day. My sons Robert and Patrick took the rooster to a city far, far away, so it may never bother us again. My sons have successfully arrived in Paris.                                                                        |
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

| 161 | Ruth    | Sometime within ten minutes of the theft,
                  I saw the thief get into a car in the bakery parking lot and drive away.
                  If you have security footage from the bakery parking lot,
                  you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | I don't know the thief's name, but it was someone I recognized.
                  Earlier this morning, before I arrived at Emma's bakery,
                  I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
                  In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
                  The thief then asked the person on the other end of the phone to purchase the flight ticket. |
*/

-----------------------------------------------------------------------------------------------------------------------

SELECT a.*
FROM airports a
WHERE a.city = "Fiftyville"
;

/*
+----+--------------+-----------------------------+------------+
| id | abbreviation |          full_name          |    city    |
+----+--------------+-----------------------------+------------+
| 8  | CSF          | Fiftyville Regional Airport | Fiftyville |
+----+--------------+-----------------------------+------------+
*/

-----------------------------------------------------------------------------------------

SELECT f.*
FROM flights f
WHERE
    f.day = 29 AND
    f.month = 7 AND
    f.year = 2023 AND
    f.origin_airport_id = 8
ORDER BY
    f.hour ASC,
    f.minute ASC
;

/*
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
| 43 | 8                 | 1                      | 2023 | 7     | 29  | 9    | 30     |
| 23 | 8                 | 11                     | 2023 | 7     | 29  | 12   | 15     |
| 53 | 8                 | 9                      | 2023 | 7     | 29  | 15   | 20     |
| 18 | 8                 | 6                      | 2023 | 7     | 29  | 16   | 0      |
+----+-------------------+------------------------+------+-------+-----+------+--------+

+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
*/

--------------------------------------------------------------------------------------------
SELECT pa.*, pe.id ,pe.name, pe.phone_number, pe.license_plate
FROM passengers pa
JOIN people pe
    ON pe.passport_number = pa.passport_number
WHERE
    pa.flight_id = 36 AND
    pe.license_plate IN (
        SELECT s.license_plate
        FROM bakery_security_logs s
        WHERE
            s.day = 28 AND
            s.month = 7 AND
            s.year = 2023 AND
            s.hour = 10 AND
            s.minute BETWEEN 15 AND 25
    )
;
/*
Suspects
+-----------+-----------------+------+--------+----------------+---------------+
| flight_id | passport_number | seat |  name  |  phone_number  | license_plate |
+-----------+-----------------+------+--------+----------------+---------------+
| 36        | 1695452385      | 3B   | Sofia  | (130) 555-0289 | G412CB7       |
| 36        | 5773159633      | 4A   | Bruce  | (367) 555-5533 | 94KL13X       |
| 36        | 8294398571      | 6C   | Kelsey | (499) 555-9472 | 0NTHK55       |
| 36        | 8496433585      | 7B   | Luca   | (389) 555-5198 | 4328GD8       |
+-----------+-----------------+------+--------+----------------+---------------+

*/
----------------------------------------------------------------------------------------------------------------------


SELECT a.*, p.name, p.passport_number
FROM atm_transactions a
JOIN bank_accounts b
    ON b.account_number = a.account_number
JOIN people p
    ON p.id = b.person_id
WHERE
    a.day = 28 AND
    a.month = 7 AND
    a.year = 2023 AND
    a.transaction_type = "withdraw" AND
    a.atm_location = "Leggett Street"
;

/*
Intersecting with prior query we have Bruce and Luca as main suspects
+-----+----------------+------+-------+-----+----------------+------------------+--------+---------+-----------------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |  name   | passport_number |
+-----+----------------+------+-------+-----+----------------+------------------+--------+---------+-----------------+
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     | Bruce   | 5773159633      |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     | Diana   | 3592750733      |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     | Brooke  | 4408372428      |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     | Kenny   | 9878712108      |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     | Iman    | 7049073643      |
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     | Luca    | 8496433585      |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     | Taylor  | 1988161715      |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     | Benista | 9586786673      |
+-----+----------------+------+-------+-----+----------------+------------------+--------+---------+-----------------+
*/


---------------------------------------------------------------------------------------------------



SELECT *
FROM phone_calls ph
WHERE
    ph.day = 28 AND
    ph.month = 7 AND
    ph.year = 2023 AND
    ph.duration < 60 AND
    ph.caller IN ("(367) 555-5533", "(389) 555-5198")
;

/*
+-----+----------------+----------------+------+-------+-----+----------+
| id  |     caller     |    receiver    | year | month | day | duration |
+-----+----------------+----------------+------+-------+-----+----------+
| 233 | (367) 555-5533 | (375) 555-8161 | 2023 | 7     | 28  | 45       |
+-----+----------------+----------------+------+-------+-----+----------+

The thief is Bruce
*/

--------------------------------------------------------------------------------------------

SELECT p.*
FROM people p
WHERE p.phone_number = "(375) 555-8161"
;

/*
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
+--------+-------+----------------+-----------------+---------------+

The accomplice is Robin
*/

-----------------------------------------------------------------------------------------------------
SELECT a.*
FROM airports a
WHERE a.id = 4
;

/*
+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+
*/
