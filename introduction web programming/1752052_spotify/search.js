const SPOTIFY_PATH='https://api.spotify.com/v1/search';
  
  function Search(){
  const textInput = document.getElementById('album_id');
  const ids = textInput.value;
  url = SPOTIFY_PATH + "?q="+ids+"&type=track%2Cartist&market=US&limit=10&offset=5";

  function onResponse(response){
    return response.json();
  }

  function onJsonReady(json){
    if (!json.tracks) {
      return;
    }

  console.log(json);
    
  const divContainer = document.getElementById('album-container');
  divContainer.textContent = "";
  
  for(var album of json.tracks.items){
    const divItem = document.createElement("div");
    const albumName = document.createElement("p");
    const linkAlbum = document.createElement("a");
    const image = document.createElement("img");

    var img = album.album.images[0].url;
    image.src = img;
    divItem.appendChild(image);

    albumName.innerHTML = "Album name: " + album.album.name ;
    albumName.style.margin = 0;
    divItem.appendChild(albumName);

    linkAlbum.href = album.album.external_urls.spotify;
    linkAlbum.textContent = "Link Spotify";
    divItem.appendChild(linkAlbum); 

    divContainer.appendChild(divItem);
  }
}

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