

int leastInterval(char* tasks, int tasksSize, int n){
    char * searc = tasks;
    char alpha_freq[26] = {0};
    int max_count = 0,
        partlen = n + 1,
        max_freq_alpha = 0;
    int positions = 0;
    if(tasksSize <=1 ) return tasksSize;
    //get every alpha freq
    for(int i =0 ;i<tasksSize; i++){
        int alpha_num = tasks[i] - 'A';
        alpha_freq[alpha_num]++;
        if(alpha_freq[alpha_num] >max_count){
            max_count = alpha_freq[alpha_num];
            max_freq_alpha = 1;
        }else if (alpha_freq[alpha_num] == max_count){
            max_freq_alpha++;
        }
        *searc++;
    }
    //find chunk
    int static_chunk = max_count-1;
    int space_chunk = partlen - max_freq_alpha; // 每一块剩余位置
    int space_total = space_chunk * static_chunk; //总剩余位置
    int taskleft = tasksSize - max_count * max_freq_alpha; // 总剩余字符
    int idles = 0 > (space_total - taskleft) ? 0 : (space_total - taskleft);
    //return positions numbers
    return tasksSize+idles;
}