<?php
class A
{
  // Members

  // A private member named "i" who has type integer 'int'
  private $i;


  // Constructors

  // NOTICE: in php, a constructor is always declared as a function, but
  // in other object oriented languages, it is not the case.
  // in PHP a constructor is always declared with the keyword __construct(...)

    public function __construct() {
  }



  // Getters

  public function getI() {
    return ($this)->i;
  }

  // Setters

  public function setI(int $_i){
    ($this)->i = $_i;
  }

  // Helpers

  public function myPrint()
  {
    echo "my I is : "
    . $this->getI();
  }

}

// The call of the constructor: instantiation of object myinstanceofa of class A
$myinstanceofa = new A;

// The call of the method setI(...)
$myinstanceofa->setI(5);

// The call of the helper method myPrint()
$myinstanceofa->myPrint();
?>
