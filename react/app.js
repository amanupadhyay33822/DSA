class Customer{
    constructor(n){
        this.name=n;
    }
    buy(){
       console.log(this.name); 
    }
}
let Customer1 = new Customer("aman")
console.log(Customer1);