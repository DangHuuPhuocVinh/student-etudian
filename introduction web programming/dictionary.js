const SPOTIFY_PATH='https://localhost/3000';
  
  function Search(){
  const textInput = document.getElementById('word');
  const ids = textInput.value;
  url = SPOTIFY_PATH ;

  function onResponse(response){
    return response.json();
  }

  function onJsonReady(json){
    if (!json.word) {
      return;
    }

  console.log(json);
    
  const divContainer = document.getElementById('');
  divContainer.textContent = "";
  
  f
fetch(url,
  {
   method: 'GET',
   headers: { 
     'Content-type': 'application/json; charset=UTF-8' ,
     'Accept': 'application/json',
     'Authorization': 'Bearer BQCiN7fAdFbcTIeHeWsZNFEPFDGZyi7NjHEiSEfsaePqE2-HTutNcp6eOeQUdVziUTllQkuomrLnqMH970MSZh0igvl_-Iv7lPBEu4VkpM7tWNczK0hMhAgAgzRO7sbxnvl0yiX3R1su_6nfo80_8Ugr1_R9X33h9g'}
 })

 .then(onResponse)
 .then(onJsonReady);
}