#Consider telephone book database of N clients. 
#Make use of a hash table implementation to 
#quickly look up client‘s telephone number. 
#Make use of two collision handling techniques 
#and compare them using number of 
#comparisons required to find a set of telephone 
#numbers.

def hashfunc(key,size):
	return key%size
	
def linprob(table,key,size):
	index = hashfunc(key,size)
	while table[index] is not None:
		index = (index+1)%size
	return index

def lininsert(table,key,value,size):
	index = linprob(table,key,size)
	table[index]=(key,value)
	
def quadprob(table,key,size):
	index = hashfunc(key,size)
	attempt = 1
	while table[index] is not None:
		index = (index + attempt**2)%size
		attempt = attempt + 1
	return index

def quadinsert(table,key,value,size):
	index=quadprob(table,key,size)
	table[index]=(key,value)
	
def search(table,key,size):
	index = hashfunc(key,size)
	iniindex = index
	while table[index] is not None:
		if index == table[index][0]:
			return index
		index = (index+1)%size
		if iniindex == index:
			break
	return None
	
def display(table):
	print("Hash Table: ")
	index = 0
	for item in table:
		if item:
			print("Index"+str(index)+":"+str(item))
		else:
			print("Index"+str(index)+":"+"Empty")
		index = index +1
		
def main():
	size = int(input("Enter hash table size: "))
	table = [None]*size
	while True:
		print("1. Insert")
		print("2. Search")
		print("3. Display")
		print("4. Exit")
		choice = int(input("Enetr choice: "))
		
		if choice == 1:
			key = int(input("Enter key: "))
			value = int(input("Enter value: "))
			print("1. Linear probing")
			print("2. Quadratic probing")
			probechoice = int(input("Enter choice for probing: "))
			if probechoice == 1:
				lininsert(table,key,value,size)
			elif probechoice == 2:
				quadinsert(table,key,value,size)
				
		elif choice ==2:
			key = int(input("Enter key to be searched: "))
			index = search(table,key,size)
			if index is not None:
				print(f"Element nit found at index{index}")
			else:
				print("Element not found")
			
		elif choice ==3:
			display(table)
	
		elif choice == 4:
			break
			
		else:
			print("Invalid choice.")
			
main()
