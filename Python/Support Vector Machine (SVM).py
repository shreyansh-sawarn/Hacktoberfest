#!/usr/bin/env python
# coding: utf-8

# # Support Vector Machine (SVM) 

# In[ ]:


#defining a function that will fetch the dependent variable from the user.
def svm(value):
    
#importing the required libraries 
    import pandas as pd
    from sklearn import preprocessing 
    from sklearn.metrics import accuracy_score
    from sklearn.model_selection import train_test_split
    from sklearn.metrics import confusion_matrix
    from sklearn import svm
    le=preprocessing.LabelEncoder()

#loading the dataset
    dataset=pd.read_csv("C:/Users/ASUS/Downloads/train.csv")

#getting some information about the data
    dataset.head()
    dataset.info()
    dataset.describe()
    
#label encoding the variables with object type of data    
    dataset['Sex']=le.fit_transform(dataset['Sex'])
    dataset['Embarked']=le.fit_transform(dataset['Embarked'])
    
#dropping the unnecessary columns 
    dataset=dataset.drop('Cabin', axis=1)
    dataset=dataset.drop('Name', axis=1)
    dataset=dataset.drop('PassengerId', axis=1)
    dataset=dataset.drop('Ticket', axis=1)
    
#Dividing the dataset into x and y (independent and dependent variables)    
    X=dataset.drop([value],axis=1)
    y=dataset[value]
    
"""Spliting the dataset into training and testing sets 
where 70% of the dataset is for training and 30% of the dataset is for testing."""

    X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.3,random_state=0)

#gamma=0.01 says the record will perform 99.99% accurately and C=100 says it will repeat 100 time.    
    clf=svm.SVC(gamma=0.01,C=100.0)
    
#fitting the model
    clf.fit(X_train,y_train)
    
#predicting on the unseen data
    y_pred=clf.predict(X_test)
    
#Printing the accuracy score and confusion matrix
    print("The accuracy score is:")
    print(accuracy_score(y_test,y_pred,normalize=True))
    print("--------------------------------------")
    print("The confusion matrix is:")
    print(confusion_matrix(y_test,y_pred))

#Calling the function svm and passing the dependent variable    
svm('Sex')

"""Note:
This is just for getting the essence of SVM so most of the EDA part has been skipped."""

