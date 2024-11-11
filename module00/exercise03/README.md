# Exercise 03 : Old PhoneBook

## Run code

### CMAKE
* Copy into the main.cpp file at the root of the project;
* Run program.

### Compile manually (UNIX based systems)
* Run the command `g++ -std=c++23 main.cpp -o phonebook`
* Run `./phonebook`

## Manual

### Commands:

#### ADD: add contact to phonebook

ADD -n *name* -p *phonenumber* -k *nickname*

##### Description

*ADD* adds a contact to the phonebook. All the fields are mandatory and the phone number is checked for duplication.

##### Options

> -n *name* 

Name of contact. 

> -p *phonenumber*

Phone number of contact. If duplicated, an error will show.

> -k *nickname*

Nickname for contact.

##### Example

    > ADD -n John -k Johnny -p 123


#### SEARCH: Search contact(s)

SEARCH [-i *index*]

##### Description

*SEARCH* lists all users, or just one if an index is provided.

##### Options

> -i *index*

Index of contact.

##### Example

    > SEARCH -i 2

#### BOOKMARK: Bookmark contact

BOOKMARK [-i *index*]

##### Description

*BOOKMARK* bookmarks a contact, given its index. If no index is provided, the full list of bookmarks will be shown. 

##### Options

> -i *index*

Index of contact.

##### Example

    > BOOKMARK -i 2

#### REMOVE: Remove contact

REMOVE {[-i *index*] | [-p *phonenumber*]}

##### Description

*REMOVE* removes a contact, given its index or phone number.

##### Options

> -i *index*

Index of contact.

> -p *phonenumber*

Phone number of contact.

##### Example

    > REMOVE -i 2

#### EXIT: Exit program

##### Description

*EXIT* exits the application
