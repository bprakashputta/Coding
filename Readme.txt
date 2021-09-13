# Readme

## PART 1

1. Connect to database

// initialise the database connection to the postgres database,
// with user postgres
// with host localhost
// with database name nodedemo
// with password yourpassword
// with database port number 5432
const credentials = {
  user: "postgres",
  host: "localhost",
  database: "nodedemo",
  password: "yourpassword",
  port: 5432,
};


// asynchronous function call to implement database connection
async function dbConnectionDemo(){

// initialise client session
  const client = new Client(credentials);
// connect client to database
  await client.connect();
// perform query over the database
  const now = await client.query("SELECT NOW()");
// close client connection to database
  await client.end();
}

2. Save data to database

// asynchronous function to registerUser
async function registerPerson(person) {

// initialise database pool connection using credentials from above answer
  const pool = new Pool(credentials);

// query text
  const text = `
    INSERT INTO people (pizza_id, order_date,delivery_time, instructions)
    VALUES ($1, $2, $3, $4)
    RETURNING id
  `;

// database query condition values to insert into DB
  const values = [person.fullname, person.gender, person.phone, person.age];

// Perform the insert query on the table and insert the values into database
  return pool.query(text, values);
}  
  
  
3. Get last two orders user_data

// asynchronous function call to getPerson details using personID 
async function getPerson(personId) {

// intialise database connection pool
  const pool = new Pool(credentials);

// SQL query to return the person details as given in the question 
  const text = `SELECT customer.customer_id, customer.first_name, customer.last_name, customer.city, customerorders.order_id, customerorders.order_date, customerorders.extra_instruction, customerorders.delivery_time, customerorders.pizza_id from customer JOIN customerorders WHERE customer.customer_id = customerorders.customer_id ORDER BY TIMESTAMP DESC LIMIT 2`;

// check for the value matching personId in the table
  const values = [personId];

// return the values that match personId by performing the databse connection pool query
  return pool.query(text, values);
}


// php code to return last 2 order details 
<?php
// import the  database connection file in the code
include "dbConn.php"; // Using database connection file here

// sql query to to fetch data from the database.
// my_sqli_query() function takes
// database connection object and query text as input
// and returns an array containing query data as output
$records = mysqli_query($db,"SELECT customer.customer_id, customer.first_name, customer.last_name, customer.city, customerorders.order_id, customerorders.order_date, customerorders.extra_instruction, customerorders.delivery_time, customerorders.pizza_id from customer JOIN customerorders WHERE customer.customer_id = customerorders.customer_id ORDER BY TIMESTAMP DESC LIMIT 2"); // fetch data from database

// while the array has data,
// iterate the array fetched from the database
while($data = mysqli_fetch_array($records))
{
?>
// div block to print order_date value
    <div><?php echo $data['order_date']; ?></div>
// div block to print delivery_time value
    <div><?php echo $data['delivery_time']; ?></div>
// div block to print extra_instruction value
    <div><?php echo $data['extra_instruction']; ?></div>	
// div block to print first_name value
    <div><?php echo $data['first_name']; ?></div>
<?php
}
?>


## PART 2

A: 

// HTTP Post request using AJAX
// open url with post request 
xhr.open("POST", url, true);
// set HTTP request headers
xhr.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
// set JSON object data with the request
xhr.send(json_object)

C: 
// set response text for the response received for the request. 
response(this.responseText);