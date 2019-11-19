float freq_finder(const float Fs,
                  const float f_init, int *flag){

  float f_aparente=f_init;
  *flag=1; //valor padrao para a variavel

  //verifica se a frequencia investigada sofre aliasing
  if(f_init>(Fs/2)){
    //calcula o resto da divisao entre as frequencias
    f_aparente=fmod(f_init/Fs, 1);
    if(f_aparente<=0.5){
      //se o resto e menor ou igual a 1/2, estamos
      //no semicirculo positivo
      f_aparente=f_aparente*Fs;
    }
    else{
      //caso contrario, estamos no semicirculo negativo
      f_aparente=(1-f_aparente)*Fs;
      *flag=-1;
    }
  }

  return f_aparente;
}
