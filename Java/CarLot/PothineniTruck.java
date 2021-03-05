public class PothineniTruck extends PothineniVehicle
{
	public PothineniTruck(int FC,int FH,int S,double C)
	{
		super(FC,FH,S,C);
	}
	
	public String cargoContainer()
	{
		return "Trunk space is " + Cargo;
	}
	
	public String Description()
	{
		return "This truck can seat " + Seating + " passangers.\nThe truck has a cargo volume of " + Cargo + ".\nThe fuel economy is " + FuelCity + "city and " + FuelHigh + "highway miles.";
	} 
}