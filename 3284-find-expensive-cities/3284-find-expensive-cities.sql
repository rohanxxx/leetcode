# Write your MySQL query statement below
WITH NationalAvg AS (
    SELECT AVG(price) AS national_avg_price
    FROM Listings
),

CityAvg AS (
    SELECT city, AVG(price) as city_avg_price
    FROM Listings
    GROUP BY city
)

SELECT city
FROM CityAvg, NationalAvg
WHERE city_avg_price > national_avg_price
ORDER BY city ASC