import java.util.Scanner;
import java.util.ArrayList;

public class PothineniInventory
{
	public static void main(String[]args)
	{
		Item item;
		String ItemName;
		int stocknum = 1000;
		int stock;
		String choice = " ";
		
		ArrayList<Item>inventory = new ArrayList<Item>();
		
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Pothineni's Sporting Goods Inventory System");
		
		do
		{
			System.out.print("\n<A>dd an item/<D>iscountinue an item/display <S>tock for an item/<Q>uit?");
			choice = scan.next();
			
			if(choice.equalsIgnoreCase("a"))
			{
				System.out.print("\nEnter the item name: ");
				ItemName=scan.next();
				
				System.out.print("\nEnter the amount in stock: ");
				stock=scan.nextInt();
				
				item = new Item(ItemName, stocknum, stock);
				
				inventory.add(item);
				
				System.out.print("\nItem has been added to inventory. Stock number is: " + item.getStockNumber());
				
				stocknum= stocknum + 1;
			}
			
			else if(choice.equalsIgnoreCase("d"))
			{
				System.out.print("\nEnter the stock number of the item to be discontinued: ");
				int temp=scan.nextInt();
				
				for(Item i: inventory)
				{
					if(i.getStockNumber()==temp )
					{
						Item item2= new Item("Discontinued", i.getStockNumber(), 0);
						
						inventory.set((i.getStockNumber() - 1000),item2);
					}
				}
				
			}
			
			else if(choice.equalsIgnoreCase("s"))
			{
				System.out.print("\nEnter the stock number of the item: ");
				int temp=scan.nextInt();
				
				for(Item i: inventory)
				{
					if(i.getStockNumber()==temp )
					{
						System.out.print("\nThe stock is: " + i.getStock());
					}
				}
			}
			
			
		}while(!(choice.equalsIgnoreCase("q")));
	}
}