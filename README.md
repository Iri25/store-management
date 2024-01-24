# store-management
C++ application with a 4-layered architecture: data access layer (Domain), persistence layer (Repository), business layer (Service) and presentation layer (UserInterface). The data is saved in a txt file. Functionality tests were performed. The main class is Applications. Key concepts are polymorphism, storage in files.

Application for managing an online store. An online store has a list of products available, characterized by (unique) name, price and number of copies available. The application allows the purchase and return of products. The user can buy or return a certain number of products. Supported operations are:
1. Adding product
2. Viewing the products
3. Updating product
4. Deleting product
5. Buying products
[^1]:When the user wants to purchase products, he can choose one more product and the desired quantity for each product. The transaction is considered to be carried out only if that all given products exist and have enough copies available, in which case the number of copies available in stock for each product will be updated and a success message will be displayed. Otherwise, an error message will be displayed in the form 'product X does not exist, [product Y does not have enough units available,...etc] (a list of errors for each product in the list given by user that could not be purchased and the reason for this).
7. Return of products
The buyer can only return one product at a time, specifying the name and quantity. The transaction is considered successful if the respective product exists, in which case the number of copies available in stock is updated. Otherwise, the error message 'No there is no product with the given name' and the user has the option to try again or give up.
