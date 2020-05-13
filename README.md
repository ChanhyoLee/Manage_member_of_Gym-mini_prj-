# Manage_member_of_Gym, mini_project

21700589 ChanhyoLee
-------------------

> + **Abstract**
>> This program is for managing members registered in the gym. Each member's name, birthday, gender, registeration date, expiration date can be saved, changed, and viewed. You can check simple statistics about gender or age and check out members who have expired. You can also import or save data files and save them in report format. The data structure was prevented from using the linked list to inefficiently waste memory space in the array.

> + **Functions**
>> + <span style="color:red">Create</span>
>> 1. add a record
>>> add from keyboard/a data file to memory
>> 2. print all records
>>> print all data of whole members to the screen
>> + <span style="color:red">Read</span>
>> 3. show members
>>> print data of members who satisfy a certain condition
>> 4. end member
>>> print data of members who have no more remain date
>> 5. load member file
>>> load data(add data) of members from member file to memory
>> 6. save as file
>>> save all data from memory to txt file
>> 7. save as report
>>> save all data from memory to txt file with some format
>> + <span style="color:red">Update</span>
>> 8. change member data
>>> change some data of a member
>> 9. add end date
>>> add one month period of a member
>> + <span style="color:red">Delete</span>
>> 10. delete member
>>> delete all members or some members who satisfy a certain condition
>> + <span style="color:red">Extra</span>
>> 11. sort
>>> sort all members by age/name/registered date
>> 12. show statistics
>>> show statistics about gender or age
>> 13. count
>>> count the number of all members

> +**How to input**
>> You can input data from single_data_file.txt, data_file.txt or keyboard.
>> Here is a input format.
Name: *Full name*
Birthday: *dd.mm.yyyy*
Gender: *F for female/M for Male*
Register_date: *dd.mm.yyyy*
End_date: *dd.mm.yyyy*

>>> You have to input a single empty line end of data file!!!
