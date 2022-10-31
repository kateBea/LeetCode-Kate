int removeDuplicates(int* nums, int numsSize){
    int indexCurrent = 1;
    int indexArray = 0;
    
    while (indexArray < numsSize - 1){
        if (nums[indexArray] != nums[indexArray + 1]){
            nums[indexCurrent++] = nums[indexArray + 1];
        }
        
        ++indexArray;
    }
    
    return indexCurrent;
}