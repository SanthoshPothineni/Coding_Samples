import java.util.Scanner;
public class PothineniCarLot
{
	public static void main(String[]args)
	{
		String carChoice;
		String choice;
		int num;
		int fc=0;
		int fh=0;
		int s=0;
		int c=0;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Welcome to Pothineni's (p)Automobiles\nVehicle Entry System - Three vehicles per session");

			System.out.println("\n\nSelect a vehicle type for the car lot.");
			System.out.println("Car(C), Truck(T), or Minivan(M)");
			carChoice = scan.next();
			if(carChoice.equals("c"))
			{
				CreateVehicles();
				PothineniCar vehicle1= new PothineniCar(fc,fh,s,c);
			}
			else if(carChoice.equals("t"))
			{
				CreateVehicles();
				PothineniTruck vehicle1= new PothineniTruck(fc,fh,s,c);
			}
			else if(carChoice.equals("m"))
			{
				CreateVehicles();
				PothineniMinivan vehicle1= new PothineniMinivan(fc,fh,s,c);
			}
			
			
			
			System.out.println("\n\nSelect a vehicle type for the car lot.");
			System.out.println("Car(C), Truck(T), or Minivan(M)");
			carChoice = scan.next();
			if(carChoice.equals("c"))
			{
				CreateVehicles();
				PothineniCar vehicle2= new PothineniCar(fc,fh,s,c);
			}
			else if(carChoice.equals("t"))
			{
				CreateVehicles();
				PothineniTruck vehicle2= new PothineniTruck(fc,fh,s,c);
			}
			else if(carChoice.equals("m"))
			{
				CreateVehicles();
				PothineniMinivan vehicle2= new PothineniMinivan(fc,fh,s,c);
			}
			
			
			
			System.out.println("\n\nSelect a vehicle type for the car lot.");
			System.out.println("Car(C), Truck(T), or Minivan(M)");
			carChoice = scan.next();
			if(carChoice.equals("c"))
			{
				CreateVehicles();
				PothineniCar vehicle3= new PothineniCar(fc,fh,s,c);
			}
			else if(carChoice.equals("t"))
			{
				CreateVehicles();
				PothineniTruck vehicle3= new PothineniTruck(fc,fh,s,c);
			}
			else if(carChoice.equals("m"))
			{
				CreateVehicles();
				PothineniMinivan vehicle3= new PothineniMinivan(fc,fh,s,c);
			}
			
			System.out.println("Three vehicles added to car lot");
			
			do
			{
				System.out.println("Learn about cargo area <c>, see vehicle description<d>, or Quit<q>?");
				System.out.println("Which vehicle <1,2,3>");
				num = scan.nextInt();
				if (num==1)
				{
					if (choice.equals("c"))
					{
						vehicle1.cargoContainer();
					}
					else if(choice.equals("d"))
					{
						vehicle1.Description();
					}
				}
			}while(!(choice.equals("q")));
		
	}
	
	public static void CreateVehicles()
	{
		int fc;
		int fh;
		int s;
		int c;
	
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Enter the city fuel economy: ");
		fc=scan.nextInt();
		System.out.println("Enter the highway fuel economy: ");
		fh=scan.nextInt();			
		System.out.println("Enter the seating capacity: ");
		s=scan.nextInt();
		System.out.println("Enter the cargo volume: ");
		c=scan.nextInt();
	}
}