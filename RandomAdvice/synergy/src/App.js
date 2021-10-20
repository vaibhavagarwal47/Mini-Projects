import React, { Component } from 'react'
import axios from 'axios';
import './App.css'

class App extends Component {
  state={advice:''};
  componentDidMount(){
this.FetchAdvice()
  }
  FetchAdvice=()=>{
    axios.get('https://api.adviceslip.com/advice')
    .then((response)=>{
      const {advice}=response.data.slip;
console.log(advice);
this.setState({advice:advice});
    })
    .catch((err)=>{
      console.log(err);
    })
  }
  render() {
    return (
      <>
      <p>{this.state.advice}</p>
   
      
      <center><div class="container" >
      <button class="button"onClick={()=>this.FetchAdvice()}>new advise</button>
</div></center>
   
<input type="checkbox" id="toggle-face"/>
<label class="me" for="toggle-face">
  <span class="face"></span>
</label>
      </>
    )
  }
}

export default App
