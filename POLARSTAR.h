#ifndef POLARSTAR_h
#define POLARSTAR_h

#include "Arduino.h";

const int POLARSTAR[] =
	{
	28, //  0 = VR_phase
	30, //  1 = VY_phase
	32, //  2 = VB_phase
	34, //  3 = IR_phase
	36, //  4 = IY_phase
	38,	//  5 = IB_phase
	40,	//  6 = Watts_R_phase
	42,	//  7 = Watts_Y_phase
	44,	//  8 = Watts_B_phase
	54,	//  9 = VA_R
	56,	// 10 = VA_Y
	58,	// 11 = VA_B
	60,	// 12 = VAR_R
	62,	// 13 = VAR_Y
	64,	// 14 = VAR_B
	66,	// 15 = pfR
	68,	// 16 = pfY
	70,	// 17 = pfB
	//0xFFFF,	// 18 = Average line to neutral voltage
	//0xFFFF,	// 19 = Average line to line voltage
	2,	// 20 = Total current
	4,	// 21 = Total Watt power
	8,	// 22 = Total VA
	6,	// 23 = Total VAR
	46,	// 24 = Frequency
	16,	// 25 = Max watt demand
	18,	// 26 = Max VA demand
	1018,	// 27 = vRY
	1020,	// 28 = vYB
	1022,	// 29 = vRB
	72,	// 30 = Neutral current
	200,	// 31 = THD Voltage_R
	202,	// 32 = THD Voltage_Y
	204,	// 33 = THD Voltage_B
	206,	// 34 = THD Current_R
	208,	// 35 = THD Current_Y
	210,	// 36 = THD Current_B
	196,	// 37 = THD Average line to neutral volts
	198,	// 38 = THD Avg line current
	80,	// 39 = Maximum Current demand R_phase
	82,	// 40 = Maximum Current demand Y_phase
	84,	// 41 = Maximum Current demand B_phase
	//0xFFFF,	// 42 = THD vRY
	//0xFFFF,	// 43 = THD vYB
	//0xFFFF,	// 44 = THD vRB
	//0xFFFF,	// 45 = THD Average line to line volts
	1126,	// 46 = Average power factor pfA
	//0xFFFF,	// 47 = Watt_hr
	//0xFFFF,	// 48 = Load hours


 //Current Harmonics
  1459, // 49 = Current A, H1 Magnitude
  1465, // 50 = Current A, H2 Magnitude
  1471, // 51 = Current A, H3 Magnitude
  1477, // 52 = Current A, H4 Magnitude
  1483, // 53 = Current A, H5 Magnitude
  1489, // 54 = Current A, H6 Magnitude
  1495, // 55 = Current A, H7 Magnitude
  1501, // 56 = Current A, H8 Magnitude
  1507, // 57 = Current A, H9 Magnitude
  1513, // 58 = Current A, H10 Magnitude
  1519, // 59 = Current A, H11 Magnitude
  1525, // 60 = Current A, H12 Magnitude
  1531, // 61 = Current A, H13 Magnitude
  1537, // 62 = Current A, H14 Magnitude
  1543, // 63 = Current A, H15 Magnitude
  1549, // 64 = Current A, H16 Magnitude
  1555, // 65 = Current A, H17 Magnitude
  1561, // 66 = Current A, H18 Magnitude
  1567, // 67 = Current A, H19 Magnitude
  1573, // 68 = Current A, H20 Magnitude
  1579, // 69 = Current A, H21 Magnitude
  1585, // 70 = Current A, H22 Magnitude
  1591, // 71 = Current A, H23 Magnitude
  1597, // 72 = Current A, H24 Magnitude
  1603, // 73 = Current A, H25 Magnitude
  1609, // 74 = Current A, H26 Magnitude
  1615, // 75 = Current A, H27 Magnitude
  1621, // 76 = Current A, H28 Magnitude
  1627, // 77 = Current A, H29 Magnitude
  1633, // 78 = Current A, H30 Magnitude
  1639, // 79 = Current A, H31 Magnitude 
  
  1461, // 80 = Current B, H1 Magnitude
  1467, // 81 = Current B, H2 Magnitude
  1473, // 82 = Current B, H3 Magnitude
  1479, // 83 = Current B, H4 Magnitude
  1485, // 84 = Current B, H5 Magnitude
  1491, // 85 = Current B, H6 Magnitude
  1497, // 86 = Current B, H7 Magnitude
  1503, // 87 = Current B, H8 Magnitude
  1509, // 88 = Current B, H9 Magnitude
  1515, // 89 = Current B, H10 Magnitude
  1521, // 90 = Current B, H11 Magnitude
  1527, // 91 = Current B, H12 Magnitude
  1533, // 92 = Current B, H13 Magnitude
  1539, // 93 = Current B, H14 Magnitude
  1545, // 94 = Current B, H15 Magnitude
  1551, // 95 = Current B, H16 Magnitude
  1557, // 96 = Current B, H17 Magnitude
  1563, // 97 = Current B, H18 Magnitude
  1569, // 98 = Current B, H19 Magnitude
  1575, // 99 = Current B, H20 Magnitude
  1581, // 100 = Current B, H21 Magnitude
  1587, // 101 = Current B, H22 Magnitude
  1593, // 102 = Current B, H23 Magnitude
  1599, // 103 = Current B, H24 Magnitude
  1605, // 104 = Current B, H25 Magnitude
  1611, // 105 = Current B, H26 Magnitude
  1617, // 106 = Current B, H27 Magnitude
  1623, // 107 = Current B, H28 Magnitude
  1629, // 108 = Current B, H29 Magnitude
  1635, // 109 = Current B, H30 Magnitude
  1641, // 110 = Current B, H31 Magnitude
  //Current Harmonic C
  1463, // 111 = Current C, H1 Magnitude
  1469, // 112 = Current C, H2 Magnitude
  1475, // 113 = Current C, H3 Magnitude
  1481, // 114 = Current C, H4 Magnitude
  1487, // 115 = Current C, H5 Magnitude
  1493, // 116 = Current C, H6 Magnitude
  1499, // 117 = Current C, H7 Magnitude
  1505, // 118 = Current C, H8 Magnitude
  1511, // 119 = Current C, H9 Magnitude
  1517, // 120 = Current C, H10 Magnitude
  1523, // 121 = Current C, H11 Magnitude
  1529, // 122 = Current C, H12 Magnitude
  1535, // 123 = Current C, H13 Magnitude
  1541, // 124 = Current C, H14 Magnitude
  1547, // 125 = Current C, H15 Magnitude
  1553, // 126 = Current C, H16 Magnitude
  1559, // 127 = Current C, H17 Magnitude
  1565, // 128 = Current C, H18 Magnitude
  1571, // 129 = Current C, H19 Magnitude
  1577, // 130 = Current C, H20 Magnitude
  1583, // 131 = Current C, H21 Magnitude
  1589, // 132 = Current C, H22 Magnitude
  1595, // 133 = Current C, H23 Magnitude
  1601, // 134 = Current C, H24 Magnitude
  1607, // 135 = Current C, H25 Magnitude
  1613, // 136 = Current C, H26 Magnitude
  1619, // 137 = Current C, H27 Magnitude
  1625, // 138 = Current C, H28 Magnitude
  1631, // 139 = Current C, H29 Magnitude
  1637, // 140 = Current C, H30 Magnitude
  1643, // 141 = Current C, H31 Magnitude 

/*
1267, // 142 = Voltage A, H1 Magnitude
1273, // 143 = Voltage A, H2 Magnitude
1279, // 144 = Voltage A, H3 Magnitude
1285, // 145 = Voltage A, H4 Magnitude
1291, // 146 = Voltage A, H5 Magnitude
1297, // 147 = Voltage A, H6 Magnitude
1303, // 148 = Voltage A, H7 Magnitude
1309, // 149 = Voltage A, H8 Magnitude
1315, // 150 = Voltage A, H9 Magnitude
1321, // 151 = Voltage A, H10 Magnitude
1327, // 152 = Voltage A, H11 Magnitude
1333, // 153 = Voltage A, H12 Magnitude
1339, // 154 = Voltage A, H13 Magnitude
1345, // 155 = Voltage A, H14 Magnitude
1351, // 156 = Voltage A, H15 Magnitude
1357, // 157 = Voltage A, H16 Magnitude
1363, // 158 = Voltage A, H17 Magnitude
1369, // 159 = Voltage A, H18 Magnitude
1375, // 160 = Voltage A, H19 Magnitude
1381, // 161 = Voltage A, H20 Magnitude
1387, // 162 = Voltage A, H21 Magnitude
1393, // 163 = Voltage A, H22 Magnitude
1399, // 164 = Voltage A, H23 Magnitude
1405, // 165 = Voltage A, H24 Magnitude
1411, // 166 = Voltage A, H25 Magnitude
1417, // 167 = Voltage A, H26 Magnitude
1423, // 168 = Voltage A, H27 Magnitude
1429, // 169 = Voltage A, H28 Magnitude
1435, // 170 = Voltage A, H29 Magnitude
1441, // 171 = Voltage A, H30 Magnitude
1447, // 172 = Voltage A, H31 Magnitude


1269, // 173 = Voltage B, H1 Magnitude
1275, // 174 = Voltage B, H2 Magnitude
1281, // 175 = Voltage B, H3 Magnitude
1287, // 176 = Voltage B, H4 Magnitude
1293, // 177 = Voltage B, H5 Magnitude
1299, // 178 = Voltage B, H6 Magnitude
1305, // 179 = Voltage B, H7 Magnitude
1311, // 180 = Voltage B, H8 Magnitude
1317, // 181 = Voltage B, H9 Magnitude
1323, // 182 = Voltage B, H10 Magnitude
1329, // 183 = Voltage B, H11 Magnitude
1335, // 184 = Voltage B, H12 Magnitude
1341, // 185 = Voltage B, H13 Magnitude
1347, // 186 = Voltage B, H14 Magnitude
1353, // 187 = Voltage B, H15 Magnitude
1359, // 188 = Voltage B, H16 Magnitude
1365, // 189 = Voltage B, H17 Magnitude
1371, // 190 = Voltage B, H18 Magnitude
1377, // 191 = Voltage B, H19 Magnitude
1383, // 192 = Voltage B, H20 Magnitude
1389, // 193 = Voltage B, H21 Magnitude
1395, // 194 = Voltage B, H22 Magnitude
1401, // 195 = Voltage B, H23 Magnitude
1407, // 196 = Voltage B, H24 Magnitude
1413, // 197 = Voltage B, H25 Magnitude
1419, // 198 = Voltage B, H26 Magnitude
1425, // 199 = Voltage B, H27 Magnitude
1431, // 200 = Voltage B, H28 Magnitude
1437, // 201 = Voltage B, H29 Magnitude
1443, // 202 = Voltage B, H30 Magnitude
1449, // 203 = Voltage B, H31 Magnitude


1271, // 204 = Voltage C, H1 Magnitude
1277, // 205 = Voltage C, H2 Magnitude
1283, // 206 = Voltage C, H3 Magnitude
1289, // 207 = Voltage C, H4 Magnitude
1295, // 208 = Voltage C, H5 Magnitude
1301, // 209 = Voltage C, H6 Magnitude
1307, // 210 = Voltage C, H7 Magnitude
1313, // 211 = Voltage C, H8 Magnitude
1319, // 212 = Voltage C, H9 Magnitude
1325, // 213 = Voltage C, H10 Magnitude
1331, // 214 = Voltage C, H11 Magnitude
1337, // 215 = Voltage C, H12 Magnitude
1343, // 216 = Voltage C, H13 Magnitude
1349, // 217 = Voltage C, H14 Magnitude
1355, // 218 = Voltage C, H15 Magnitude
1361, // 219 = Voltage C, H16 Magnitude
1367, // 220 = Voltage C, H17 Magnitude
1373, // 221 = Voltage C, H18 Magnitude
1379, // 222 = Voltage C, H19 Magnitude
1385, // 223 = Voltage C, H20 Magnitude
1391, // 224 = Voltage C, H21 Magnitude
1397, // 225 = Voltage C, H22 Magnitude
1403, // 226 = Voltage C, H23 Magnitude
1409, // 227 = Voltage C, H24 Magnitude
1415, // 228 = Voltage C, H25 Magnitude
1421, // 229 = Voltage C, H26 Magnitude
1427, // 230 = Voltage C, H27 Magnitude
1433, // 231 = Voltage C, H28 Magnitude
1439, // 232 = Voltage C, H29 Magnitude
1445, // 233 = Voltage C, H30 Magnitude
1451, // 234 = Voltage C, H31 Magnitude*/
/*
1651, 
1657, 
1663, 
1669, 
1675, 
1681, 
1687, 
1693, 
1699, 
1705, 
1711, 
1717, 
1723, 
1729, 
1735, 
1741, 
1747, 
1753, 
1759, 
1765, 
1771, 
1777, 
1783, 
1789, 
1795, 
1801, 
1807, 
1813, 
1819, 
1825, 
1831, 



1653, 
1659, 
1665, 
1671, 
1677, 
1683, 
1689, 
1695, 
1701, 
1707, 
1713, 
1719, 
1725, 
1731, 
1737, 
1743, 
1749, 
1755, 
1761, 
1767, 
1773, 
1779, 
1785, 
1791, 
1797, 
1803, 
1809, 
1815, 
1821, 
1827, 
1833, 



1655, 
1661, 
1667, 
1673, 
1679, 
1685, 
1691, 
1697, 
1703, 
1709, 
1715, 
1721, 
1727, 
1733, 
1739, 
1745, 
1751, 
1757, 
1763, 
1769, 
1775, 
1781, 
1787, 
1793, 
1799, 
1805, 
1811, 
1817, 
1823, 
1829, 
1835, 


*/




1861,
1863

};

#endif
