
SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";



--
-- Database: `crud_flask`
--

-- --------------------------------------------------------

--
-- Table structure for table `phone_book`
--

CREATE TABLE IF NOT EXISTS `phone_book` (
  `id` int(5) NOT NULL,
  `name` varchar(255) NOT NULL,
  `phone` varchar(50) NOT NULL,
  `address` varchar(255) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=latin1;


CREATE TABLE sensor_data (
    id int NOT NULL AUTO_INCREMENT,
    temp varchar(255) NOT NULL,
    humidity varchar(255),
    pressure int,
    PRIMARY KEY (id)
);


--
-- Dumping data for table `phone_book`
--

INSERT INTO sensor_data (temp, humidity, pressure)
VALUES (1, 2, 3);

INSERT INTO `phone_book` (`id`, `name`, `phone`, `address`) VALUES
(16, 'Muhammad Hanif', '085733492411', 'Lamongan');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `phone_book`
--
ALTER TABLE `phone_book`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `phone_book`
--
ALTER TABLE `phone_book`
  MODIFY `id` int(5) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=21;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
