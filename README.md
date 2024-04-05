# Market-metrics
Requirement

Given keyboard commands for adding/removing stores, people, or products, statistics should be compiled on certain attributes related to specific types of stores, the average salary of people in stores, and whether individuals can afford the product they desire as mentioned in the Output Data section.

Input Data

Lines will be read until EOF. A line consists of the following elements:

- The first word will be the action you want to perform. This command can be add or remove. If this command is add, then an addition will be made; if it is remove, a deletion will be made.

- The second word is what you want to add or remove.

        - If we want to add a store, this second word can be one of the words MiniMarket, Market, SuperMarket, or Mall, followed by its name.

        - If we want to add or remove a certain person from a store or a product, this second word will be buyer or product.

        	- buyer is followed by name, the product they wish to buy (it will be considered that each client wants to buy only one product) and salary

        	- product is followed by name, type, and its price (there can be multiple products of the same kind)

        - If we want to remove a person or a product, the next input data will be the name of the person or product and the name of the store. It will be assumed there is no person with the same name in the same store. For example, if we have a line in the form remove buyer Andrei Afi, the client Andrei will be removed from the Afi mall.

Output Data

The output will consist of statistics as follows:

Number of MiniMarkets: the total number of mini-stores

Number of Markets: the total number of markets

Number of SuperMarkets: the total number of supermarkets

Number of Malls: the total number of malls

Average Salary for MiniMarkets: the average salary of customers located in mini-stores

Average Salary for Markets: the average salary of customers located in markets

Average Salary for SuperMarkets: the average salary of customers located in supermarkets

Average Salary for Malls: the average salary of customers located in malls

Products Sale in MiniMarkets: the number of people who managed to buy what they wanted from mini-stores

Products Sale in Markets: the number of people who managed to buy what they wanted from markets

Products Sale in SuperMarkets: the number of people who managed to buy what they wanted from supermarkets

Products Sale in Malls: the number of people who managed to buy what they wanted from malls
