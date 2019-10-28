-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: אוקטובר 28, 2018 בזמן 07:09 PM
-- גרסת שרת: 8.0.13
-- PHP Version: 7.2.10-0ubuntu0.18.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `projectmonopo`
--

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `chance`
--

CREATE TABLE `chance` (
  `ID` int(11) NOT NULL,
  `CardText` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Operation` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `chance`
--

INSERT INTO `chance` (`ID`, `CardText`, `Operation`) VALUES
(1, 'Advance to Go', 0),
(2, 'Advance to Illinois Ave. - If you pass Go, collect $200', 7),
(3, 'Advance to St. Charles Place – If you pass Go, collect $200', 7),
(4, 'Advance token to nearest Utility. If unowned, you may buy it from the Bank. If owned, throw dice and pay owner a total ten times the amount thrown', 8),
(5, 'Advance token to the nearest Railroad and pay owner twice the rental to which he/she is otherwise entitled. If Railroad is unowned, you may buy it from the Bank.', 8),
(6, 'Bank pays you dividend of $50 ', 50),
(7, 'Get out of Jail Free – This card may be kept until needed, or traded/sold', 4),
(8, 'Go Back 3 Spaces', 8),
(9, 'Go to Jail – Go directly to Jail – Do not pass Go, do not collect $200', 2),
(10, 'Make general repairs on all your property – For each house pay $25 – For each hotel $100', 6),
(11, 'Pay poor tax of $15', -15),
(12, 'Take a trip to Reading Railroad If you pass Go, collect $200', 7),
(13, 'Take a walk on the Boardwalk – Advance token to Boardwalk. ', 7),
(14, 'You have been elected Chairman of the Board – Pay each player $50', -50),
(15, 'Your building loan matures – Collect $150', 150),
(16, 'You have won a crossword competition - Collect $100', 100);

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `communitychest`
--

CREATE TABLE `communitychest` (
  `ID` int(11) NOT NULL,
  `CardText` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Operation` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `communitychest`
--

INSERT INTO `communitychest` (`ID`, `CardText`, `Operation`) VALUES
(1, 'Advance to Start', 5),
(2, 'Bank error in your favor – Collect $200 ', 200),
(3, 'Doctors fee – Pay $50', -50),
(4, 'From sale of stock you get $50', 50),
(5, 'Get Out of Jail Free', 4),
(6, 'Go to Jail – Go directly to jail – Do not pass Go – Do not collect $200', 3),
(7, 'Grand Opera Night – Collect $50 from every player for opening night seats', 50),
(8, 'Holiday Fund matures - Receive $100 ', 100),
(9, 'Income tax refund – Collect $20', 20),
(10, 'It is your birthday - Collect $10 from each player', 10),
(11, 'Life insurance matures – Collect $100', 100),
(12, 'Pay hospital fees of $100', -100),
(13, 'Pay school tax of $150 ', -150),
(14, 'Receive $25 consultancy fee', 25),
(15, 'You are assessed for street repairs – $40 per house – $115 per hotel', 6),
(16, 'You have won second prize in a beauty contest – Collect $10', 10),
(17, 'You inherit $100', 100);

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `High Score`
--

CREATE TABLE `High Score` (
  `id` int(11) NOT NULL,
  `name` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `points` int(11) NOT NULL,
  `rounds` int(11) NOT NULL,
  `money` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `High Score`
--

INSERT INTO `High Score` (`id`, `name`, `points`, `rounds`, `money`) VALUES
(1, 'Player b', 1000, 1, 1500),
(2, 'Player a', 180, 0, 2000),
(3, 'Player b', 1, 0, 1500),
(4, 'Player b', 0, 0, 1500),
(5, 'Testing', 33, 2, 1231),
(6, 'Player a', 0, 0, 0),
(7, 'player b', 0, 2, 23),
(8, 'sh', 0, 7, 20),
(9, 'tom', 0, 0, 0),
(10, 'alon', 0, 0, 0);

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `PlayerSaved`
--

CREATE TABLE `PlayerSaved` (
  `GameID` int(11) NOT NULL,
  `Id` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Pic` int(11) NOT NULL,
  `Money` int(11) NOT NULL,
  `Position` int(11) NOT NULL,
  `jailtime` int(11) NOT NULL,
  `cardoutjail` int(11) NOT NULL,
  `sumloan` int(11) NOT NULL,
  `countroundloan` int(11) NOT NULL,
  `loancurrentround` int(11) NOT NULL,
  `vactiontime` tinyint(1) NOT NULL,
  `takeloan` tinyint(1) NOT NULL,
  `modelPositionx` float NOT NULL,
  `modelPositiony` float NOT NULL,
  `modelPositionz` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `PlayerSaved`
--

INSERT INTO `PlayerSaved` (`GameID`, `Id`, `Pic`, `Money`, `Position`, `jailtime`, `cardoutjail`, `sumloan`, `countroundloan`, `loancurrentround`, `vactiontime`, `takeloan`, `modelPositionx`, `modelPositiony`, `modelPositionz`) VALUES
(4, 'Player a', 1, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 1.35, 1, -1.8),
(4, 'Player b', 1, 1500, 0, 0, 0, 0, 0, 0, 0, 0, -4.05, 1, 4.4),
(5, 'Player a', 1, 2000, 0, 0, 0, 0, 0, 0, 0, 0, 1.35, 1, -1.8),
(5, 'Player b', 1, 1500, 0, 0, 0, 0, 0, 0, 0, 0, -4.05, 1, 4.4),
(6, 'Player a', 1, 1442, 0, 0, 0, 0, 0, 0, 0, 0, 1.35, 1, -1.8),
(6, 'Player b', 1, 1498, 0, 0, 0, 0, 0, 0, 0, 0, -4.05, 1, 4.4),
(7, 'Player a', 1, 1500, 1, 0, 0, 0, 0, -858993460, 0, 0, 1.35, 1, -1.8),
(7, 'Player b', 2, 1500, 1, 0, 0, 0, 0, -858993460, 0, 0, -4.05, 1, 4.4),
(8, 'Player a', 1, 1500, 2, 0, 0, 0, 0, -858993460, 0, 0, 1.35, 1, -1.8),
(8, 'Player b', 2, 1500, 1, 0, 0, 0, 0, -858993460, 0, 0, -4.05, 1, 4.4);

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `property`
--

CREATE TABLE `property` (
  `Position` int(11) NOT NULL,
  `Buy_Price` int(11) NOT NULL,
  `Rent_Price` int(11) NOT NULL,
  `House_Price` int(11) NOT NULL,
  `Hotel_Price` int(11) NOT NULL,
  `Owner` int(11) NOT NULL,
  `Category` int(11) NOT NULL,
  `With_1House` int(11) NOT NULL,
  `With_2House` int(11) NOT NULL,
  `With_3House` int(11) NOT NULL,
  `With_4House` int(11) NOT NULL,
  `With_Hotel` int(11) NOT NULL,
  `Color` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Name` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `property`
--

INSERT INTO `property` (`Position`, `Buy_Price`, `Rent_Price`, `House_Price`, `Hotel_Price`, `Owner`, `Category`, `With_1House`, `With_2House`, `With_3House`, `With_4House`, `With_Hotel`, `Color`, `Name`) VALUES
(1, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 'None', 'Start'),
(2, 60, 2, 50, 250, 0, 0, 10, 30, 90, 160, 250, 'Brown', 'Mediterranean Avenue'),
(3, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 'None', 'Community Chest'),
(4, 60, 4, 50, 250, 0, 0, 20, 60, 180, 320, 450, 'Brown', 'Baltic Avenue'),
(5, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 'None', 'Income Tax'),
(6, 200, 0, 0, 0, 0, 1, 25, 50, 100, 200, 0, 'Railroads', 'Reading RailRoad'),
(7, 100, 6, 50, 250, 0, 0, 30, 90, 270, 400, 550, 'Light_Blue', 'Oriental Avenue'),
(8, 0, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0, 'None', 'Chance'),
(9, 100, 6, 50, 250, 0, 0, 30, 90, 270, 400, 550, 'Light_Blue', 'Vermont Avenue'),
(10, 120, 8, 50, 250, 0, 0, 40, 100, 300, 450, 600, 'Light_Blue', 'Connecticut Avenue'),
(11, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 'None', 'Jail'),
(12, 140, 10, 100, 500, 0, 0, 50, 150, 450, 625, 750, 'Purple', 'St. Charles Place'),
(13, 150, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 'Company', 'Electric Company'),
(14, 140, 10, 100, 500, 0, 0, 50, 150, 450, 625, 750, 'Purple', 'States Avenue'),
(15, 160, 12, 100, 500, 0, 0, 60, 180, 500, 700, 900, 'Purple', 'Virginia Avenue'),
(16, 200, 0, 0, 0, 0, 1, 25, 50, 100, 200, 0, 'Railroads', 'Pennsylvania Railroad'),
(17, 180, 14, 100, 500, 0, 0, 70, 200, 550, 750, 950, 'Orange', 'St. James Place'),
(18, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 'None', 'Community Chest'),
(19, 180, 14, 100, 500, 0, 0, 70, 200, 550, 750, 950, 'Orange', 'Tennessee Avenue'),
(20, 200, 16, 100, 500, 0, 0, 80, 220, 600, 800, 1000, 'Orange', 'New York Avenue'),
(21, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 'None', 'Free Parking'),
(22, 220, 18, 150, 750, 0, 0, 90, 250, 700, 875, 1050, 'Red', 'Kentucky Avenue'),
(23, 0, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0, 'None', 'Chance'),
(24, 220, 18, 150, 750, 0, 0, 90, 250, 700, 875, 1050, 'Red', 'Indiana Avenue'),
(25, 240, 20, 150, 750, 0, 0, 100, 300, 750, 925, 1100, 'Red', 'Illinois Avenue'),
(26, 200, 0, 0, 0, 0, 1, 25, 50, 100, 200, 0, 'Railroads', 'B. & O. Railroad'),
(27, 260, 22, 150, 750, 0, 0, 110, 330, 800, 975, 1150, 'Yellow', 'Atlantic Avenue'),
(28, 260, 22, 150, 750, 0, 0, 110, 330, 800, 975, 1150, 'Yellow', 'Ventnor Avenue'),
(29, 150, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 'Company', 'Water Works'),
(30, 280, 24, 150, 750, 0, 0, 120, 360, 850, 1025, 1200, 'Yellow', 'Marvin Gardens'),
(31, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 'None', 'Go To Jail'),
(32, 300, 26, 200, 1000, 0, 0, 130, 390, 900, 1100, 1275, 'Green', 'Pacific Avenue'),
(33, 300, 26, 200, 1000, 0, 0, 130, 390, 900, 1100, 1275, 'Green', 'North Carolina Avenue'),
(34, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 'None', 'Community Chest'),
(35, 320, 28, 200, 1000, 0, 0, 150, 450, 1000, 1200, 1400, 'Green', 'Pennsylvania Avenue'),
(36, 200, 0, 0, 0, 0, 1, 25, 50, 100, 200, 0, 'Railroads', 'Short Line Railroad'),
(37, 0, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0, 'None', 'Chance'),
(38, 350, 35, 200, 1000, 0, 0, 175, 500, 1100, 1300, 1500, 'Blue', 'Park Place'),
(39, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 'None', 'Luxury Tax'),
(40, 400, 50, 200, 1000, 0, 0, 200, 600, 1400, 1700, 2000, 'Blue', 'Boardwalk');

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `propertysaved`
--

CREATE TABLE `propertysaved` (
  `GameID` int(11) NOT NULL,
  `Position` int(11) NOT NULL,
  `Owner` int(11) NOT NULL,
  `HouseCount` int(11) NOT NULL,
  `GotHotel` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `propertysaved`
--

INSERT INTO `propertysaved` (`GameID`, `Position`, `Owner`, `HouseCount`, `GotHotel`) VALUES
(6, 2, 1, 0, 0);

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `Savedgamesetting`
--

CREATE TABLE `Savedgamesetting` (
  `GameID` int(11) NOT NULL,
  `players` int(11) NOT NULL,
  `turn` int(11) NOT NULL,
  `p1round` int(11) NOT NULL,
  `p2round` int(11) NOT NULL,
  `p3round` int(11) NOT NULL,
  `p4round` int(11) NOT NULL,
  `date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `Savedgamesetting`
--

INSERT INTO `Savedgamesetting` (`GameID`, `players`, `turn`, `p1round`, `p2round`, `p3round`, `p4round`, `date`) VALUES
(5, 2, 1, 1, 1, 0, 0, '2018-10-03'),
(6, 2, 2, 1, 1, 0, 0, '2018-10-05'),
(7, 2, 1, 0, 0, 0, 0, '2018-10-16'),
(8, 2, 1, 0, 0, 0, 0, '2018-10-16');

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `Trivia`
--

CREATE TABLE `Trivia` (
  `ID` int(11) NOT NULL,
  `Question` varchar(70) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `answer1` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `answer2` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `answer3` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `answer4` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `correctanswer` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `Trivia`
--

INSERT INTO `Trivia` (`ID`, `Question`, `answer1`, `answer2`, `answer3`, `answer4`, `correctanswer`) VALUES
(1, 'Which country did Germany invade on the 1st of September 1939?', 'France', 'Czechoslovakia', 'Poland', 'Finland', 'Poland'),
(2, 'What U.S. agency motto is Fidelity, Bravery, Integrity?', 'FBI', 'CIA', 'CSI', 'NCA', 'FBI'),
(3, 'In a photo editing program, what do the letters RGB stand for?', 'Red, Gold, Blue\r\n', 'Ruby, Green, Blue', 'Red, Green, Black', 'Red, Green, Blue', 'Red, Green, Blue'),
(4, 'What is the largest country, by area, that has only one time zone?', 'Australia', 'China', 'Turkey', 'Russia', 'China'),
(5, 'What restaurant franchise advises you to \'Eat Fresh\'?', 'McDonald\'s', 'KFC', 'Subway', 'Taco Bell', 'Subway'),
(6, 'How many spaces are on a standard Monopoly board?', '40', '20', '80', '60', '40'),
(7, 'What is the name for the Jewish New Year?', 'Yom Kippur', 'Kwanzaa', 'Hanukkah', 'Rosh Hashanah', 'Rosh Hashanah'),
(8, 'Which country hosted the Summer Olympics in 2016?', 'Spain', 'Brazil', 'China', 'Greece', 'Brazil'),
(9, 'In which language was the book \'War and Peace\' originally written?', 'German', 'Russian', 'English', 'French', 'Russian'),
(10, 'What religion is the most practiced one in India?', 'Shinto', 'Sikhism', 'Islam', 'Hinduism', 'Hinduism'),
(11, 'Which of these NBA franchises has never signed LeBron James?', 'Miami Heat', 'Los Angeles Lakers', 'Boston Celtics', 'Cleveland Cavaliers', 'Boston Celtics'),
(12, 'What year did Albert Einstein die?', '1954', '1949', '1960', '1955', '1955'),
(13, 'Which is the largest planet in the solar system?', 'Jupiter', 'Neptune', 'Earth', 'Mars', 'Jupiter'),
(14, 'How many Presidents have there been of the USA?', '36', '29', '46', '45', '45'),
(15, 'What colour is Cerulean?', 'Red', 'Blue', 'Yellow', 'Green', 'Blue'),
(16, 'What are a group of Dolphins called?', 'School', 'Herd', 'Pod', 'Pool', 'Pod'),
(17, 'Who invented Penicillin?', 'Alexandra Fleming', 'Thomas Edison', 'Marie Curie', 'George Orwell', 'Alexandra Fleming'),
(18, 'What date was President John F Kennedy assassinated?', 'November 22 1962', 'November 22 1963', 'October 29 1964', 'November 24 1962', 'November 22 1963'),
(19, 'How many men have walked on the moon?', '10', '5', '12', '9', '12'),
(20, 'Who has won the most Academy Awards?', 'James Cameron', 'Walt Disney', 'Katherine Hepburn', 'Steven Spielberg', 'Walt Disney'),
(21, 'What is the currency of Brazil?', 'Dollar', 'The Bhat', 'Real', 'Krona', 'Real'),
(22, 'What was the first country to give women the vote in 1893?', 'America', 'Australia', 'New Zealand', 'Iceland', 'New Zealand'),
(23, 'What is the oldest known story in the world?', 'The Bible', 'The Histories', 'Epic of Gilgamesh', 'The Odyssey', 'Epic of Gilgamesh'),
(24, 'In 1066 at the Battle of Hastings, King Harold was defeated by:', 'Harald', 'William', 'Tostig', 'Ragnar', 'William'),
(25, 'Sliced bread was invented in:', 'America in 1928', 'France in 1789', 'Australia in 1897', 'Scotland in 1902', 'America in 1928'),
(26, 'What year did the Berlin Wall fall?', '1988', '1994', '1991', '1989', '1989'),
(27, 'Where in the body is the scapular muscle?', 'Knee', 'Shoulder', 'Head', 'Arm', 'Shoulder'),
(28, 'According to the Red Cross what is the most common Blood Type?', 'Blood Type A', 'Blood Type O', 'Blood Type B', 'Blood Type B', 'Blood Type O'),
(29, 'What is the smallest bone in the human body?', 'Stapes', 'Pinna', 'Clavicle', 'Fibula', 'Stapes'),
(30, 'Where in the body is the thyroid gland found?', 'Stomach', 'Underarm', 'Neck', 'Head', 'Neck');

-- --------------------------------------------------------

--
-- מבנה טבלה עבור טבלה `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `username` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `password` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `f_name` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `l_name` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `email` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL,
  `gender` enum('M','F','') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `admin` tinyint(4) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- הוצאת מידע עבור טבלה `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `f_name`, `l_name`, `email`, `gender`, `admin`) VALUES
(1, 'shai', '1234', 'Shai', 'Mizrahi', 'othersidee@gmail.com', 'M', 1),
(2, 'alon', '1212', 'Alon', 'Even Yosef', 'alon1421@gmail.com', 'F', 1);

--
-- Indexes for dumped tables
--

--
-- אינדקסים לטבלה `chance`
--
ALTER TABLE `chance`
  ADD PRIMARY KEY (`ID`);

--
-- אינדקסים לטבלה `communitychest`
--
ALTER TABLE `communitychest`
  ADD PRIMARY KEY (`ID`);

--
-- אינדקסים לטבלה `High Score`
--
ALTER TABLE `High Score`
  ADD UNIQUE KEY `id` (`id`);

--
-- אינדקסים לטבלה `property`
--
ALTER TABLE `property`
  ADD PRIMARY KEY (`Position`);

--
-- אינדקסים לטבלה `propertysaved`
--
ALTER TABLE `propertysaved`
  ADD PRIMARY KEY (`GameID`,`Position`);

--
-- אינדקסים לטבלה `Savedgamesetting`
--
ALTER TABLE `Savedgamesetting`
  ADD PRIMARY KEY (`GameID`);

--
-- אינדקסים לטבלה `Trivia`
--
ALTER TABLE `Trivia`
  ADD PRIMARY KEY (`ID`);

--
-- אינדקסים לטבלה `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `chance`
--
ALTER TABLE `chance`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;

--
-- AUTO_INCREMENT for table `communitychest`
--
ALTER TABLE `communitychest`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `property`
--
ALTER TABLE `property`
  MODIFY `Position` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=41;

--
-- AUTO_INCREMENT for table `Trivia`
--
ALTER TABLE `Trivia`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=43;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
