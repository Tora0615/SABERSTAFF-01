int delay_time = 30;  

// demo list
// uint8_t timeListSize = 100;   
// const float timeList[100] PROGMEM = {1,2,3,4,5,6,7,8,11,14,17,20,23,26,29,32,35,38,41,44,47,50,53,56,59,62,65,68,71};
// const byte styleList[100] PROGMEM = {0,1,2,3,4,5,10,11,50,51,52,53,54,55,56,57,58,60,61,62,63,64,65,66,67,70,71,72,73}; 

/* bug : len = 1 will not work*/


uint8_t timeListSize = 74;
const float timeList[74] PROGMEM = {
	08.87, 23.87, 38.80, 39.30, 40.67, 41.17, 42.55, 43.05, 44.33, 44.83, 46.27, 46.77, 48.15, 48.65, 50.00, 50.50, 51.93, 52.43, 
	53.67, 57.50, 61.30, 61.80, 64.96, 65.46, 68.67, 69.17, 72.53, 73.03,    
	76.50, 78.37, 80.26, 82.17, 84.00, 86.00, 88.00,    
	90.57, 91.50, 92.43, 93.38, 95.09, 98.10, 105.56, 106.76, 107.96,     
	110.20, 114.06, 117.60, 121.26, 126.85, 127.10, 127.90, 128.82, 143.96, 146.00, 147.76, 158.44, 158.94, 188.93, 
	189.75, 197.10, 200.66, 204.06, 211.37, 216.97, 217.89, 233.93, 235.03, 236.85, 237.83, 238.57, 239.57, 241.15, 245.23, 
	259.06 };

const byte styleList[74] PROGMEM = {
	// A 
	10,
	50,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,
	56,53,55,53,55,53,55,53,55,53,  
	1,3,4,0,5,3,2, 
	10,52,58,55,58,52,51,50,10, 
	70,70,10,70,10,70,10,71,10,10,72,10,73,10, 
	60,10,61,62,63,10,67,10,10,10,10,10,10,52,52

	// B 
//	 10,
//	 10,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,
//	 56,53,55,53,55,53,55,53,55,53, 
//	 1,3,4,0,5,3,2, 
//	 10,52,58,55,58,52,51,50,10,		
//	 70,10,10,70,10,70,10,71,72,72,72,10,73,10,
//	 60,10,61,62,63,10,67,10,52,52,52,10,58,10,58


	// C 
//	 10,
//	 10,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,
//	 56,53,55,53,55,53,55,53,55,53, 
//	 1,3,4,0,5,3,2, 
//	 10,52,58,55,58,52,51,50,10,			
//	 10,70,10,70,10,70,10,71,72,72,72,10,73,10,
//	 60,10,61,62,63,10,67,10,52,52,52,10,58,10,58


	// D 
//	 10,
//	 10,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,
//	 56,53,55,53,55,53,55,53,55,53, 
//	 1,3,4,0,5,3,2, 
//	 10,52,58,55,58,52,51,50,10,			
//	 70,10,10,70,10,70,10,71,10,72,72,10,73,10,
//	 60,10,61,62,63,10,67,10,10,52,10,10,58,10,55


	// E 
//	 10,
//	 10,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,52,50,
//	 56,53,55,53,55,53,55,53,55,53, 
//	 1,3,4,0,5,3,2, 
//	 10,52,58,55,58,52,51,50,10,			
//	 10,70,10,70,10,70,10,71,10,72,72,10,73,10,
//	 60,10,61,62,63,10,67,10,10,52,10,10,58,10,55

};